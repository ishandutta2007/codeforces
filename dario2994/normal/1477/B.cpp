#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 1<<18;
int ff[2*MAXN];
int flag[2*MAXN]; // -1, 0, 1

void deflag(int v, int l, int r) {
    if (flag[v] == -1) return;
    int sz = (r-l+1)/2;
    ff[2*v] = sz*flag[v];
    flag[2*v] = flag[v];
    ff[2*v+1] = sz*flag[v];
    flag[2*v+1] = flag[v];
    flag[v] = -1;
}


int get(int v, int l, int r, int a, int b) {
    if (a <= l and r <= b) return ff[v];
    if (r < a or b < l) return 0;
    deflag(v, l, r);
    int m = (l+r)/2;
    return get(2*v, l, m, a, b) + get(2*v+1, m+1, r, a, b);
}

void update(int v, int l, int r, int a, int b, int val) {
    // dbg(v, l, r, a, b, val);
    if (a <= l and r <= b) {
        flag[v] = val;
        ff[v] = (r-l+1)*val;
        return;
    }
    if (r < a or b < l) return;
    deflag(v, l, r);
    int m = (l+r)/2;
    update(2*v, l, m, a, b, val);
    update(2*v+1, m+1, r, a, b, val);
    ff[v] = ff[2*v] + ff[2*v+1];
}

void solve() {
    int n, q;
    cin >> n >> q;
    string S, T;
    cin >> S >> T;

    int maxn = 1;
    while (maxn <= n) maxn *= 2;
    for (int i = 1; i < 2*maxn; i++) flag[i] = -1;
    for (int i = maxn; i < maxn + n; i++) ff[i] = T[i-maxn]-'0';
    for (int i = maxn-1; i >= 1; i--) ff[i] = ff[2*i] + ff[2*i+1];
    // update(1, 0, maxn, 0, 4, 0);
    // cout << get(1, 0, maxn-1, 3, 3) << endl;
    // return;
    
    vector<pair<int,int>> pp(q);
    for (int i = 0; i < q; i++) cin >> pp[i].first >> pp[i].second;
    for (int _ = q-1; _ >= 0; _--) {
        int l = pp[_].first, r = pp[_].second;
        l--, r--;
        int zeros = 0, ones = 0;
        ones = get(1, 0, maxn-1, l, r);
        zeros = r-l+1-ones;
        if (zeros == ones) {
            cout << "NO\n";
            return;
        }
        // dbg(l, r, zeros, ones);
        if (zeros < ones) update(1, 0, maxn-1, l, r, 1);
        if (ones < zeros) update(1, 0, maxn-1, l, r, 0);
    }
    for (int i = 0; i < n; i++) {
        // dbg(i);
        if (get(1, 0, maxn-1, i, i) != S[i]-'0') {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) solve();
}