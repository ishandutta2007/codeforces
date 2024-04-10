#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

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

void update(int v, int x) {
    v += MAXN;
    ff[v] = x;
    while (v > 1) {
        v >>= 1;
        ff[v] = max(ff[2*v], ff[2*v+1]);
    }
}

int query(int v, int l, int r, int a, int b) {
    if (r < a or b < l) return 0;
    if (a <= l and r <= b) return ff[v];
    int m = (l+r)/2;
    return max(query(2*v, l, m, a, b), query(2*v+1, m+1, r, a, b));
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    set<int> coord;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0) coord.insert(a[i]);
    }
    a.push_back(1e9 + 1);
    n++;
    coord.insert(a.back());
    
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i], coord.insert(b[i]);
    sort(b.begin(), b.end());

    coord.insert(0);
    map<int,int> compress;
    vector<int> uncompress;
    for (int x: coord) {
        int sz = compress.size();
        compress[x] = sz;
        uncompress.push_back(x);
    }
    compress[-1] = -1;

    for (int i = 0; i < n; i++) a[i] = compress[a[i]];
    for (int i = 0; i < m; i++) b[i] = compress[b[i]];

    reverse(b.begin(), b.end());
    
    vector<int> lis(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            int x = a[i];
            int q = query(1, 0, MAXN-1, 0, x-1);
            lis[i] = 1+q;
            update(x, 1 + q);
        } else {
            for (int i = MAXN+1; i < 2*MAXN; i++) ff[i] = max(ff[i], ff[i-1]);
            for (int x: b) ff[MAXN+x] = 1 + ff[MAXN+x-1];
            for (int v = MAXN-1; v >= 1; v--) ff[v] = max(ff[2*v], ff[2*v+1]); 
        }
    }
    reverse(b.begin(), b.end());
    
    int it = n-1;
    vector<bool> used(m, false);
    for (int len = lis.back(); len > 1; len--) {
        bool found = false;
        for (int i = it-1; i >= 0; i--) {
            if (a[i] != -1 and a[i] < a[it] and lis[i] == len-1) {
                found = true;
                it = i;
                break;
            }
        }
        if (found) continue;
        for (int i = it-1; i >= 0; i--) {
            if (a[i] != -1) continue;
            // dbg(it, len, i, a[it], b);
            int pos = prev(lower_bound(b.begin(), b.end(), a[it])) - b.begin();
            used[pos] = true;
            a[i] = b[pos];
            it = i;
            break;
        }
    }
    // dbg(used, b);

    it = 0;
    for (int i = 0; i < n-1; i++) {
        if (a[i] == -1) {
            while (used[it]) it++;
            a[i] = b[it];
            it++;
        }
        cout << uncompress[a[i]] << " ";
    }
    cout << "\n";
}