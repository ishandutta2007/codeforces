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
LL ss[2*MAXN];
LL mm[2*MAXN]; // min
bool ff[2*MAXN];

void deflag(int v) {
    if (!ff[v]) return;
    ff[v] = false;
    ff[2*v] = ff[2*v+1] = true;
    mm[2*v] = mm[2*v+1] = mm[v];
    ss[2*v] = ss[2*v+1] = ss[v]/2;
}

// set to!
void update(int v, int l, int r, int a, int b, LL x) {
    if (r < a or b < l) return;
    if (a <= l and r <= b) {
        mm[v] = x;
        ss[v] = (r-l+1)*x;
        ff[v] = true;
        return;
    }
    deflag(v);
    int m = (l+r)/2;
    update(2*v, l, m, a, b, x);
    update(2*v+1, m+1, r, a, b, x);
    ss[v] = ss[2*v] + ss[2*v+1];
    mm[v] = min(mm[2*v], mm[2*v+1]);
}

int FirstLeq(LL x) {
    int v = 1;
    while (v < MAXN) {
        deflag(v);
        if (mm[2*v] <= x) v = 2*v;
        else v = 2*v+1;
    }
    return v-MAXN;
}

// return it such that 0 + 1 + ... + it is too much
int FirstGreaterPref(LL x) {
    int v = 1;
    while (v < MAXN) {
        deflag(v);
        if (ss[2*v] <= x) {
            x -= ss[2*v];
            v = 2*v+1;
        } else v = 2*v;
    }
    return v-MAXN;
}

// Compute sum on 0, 1, ..., x
LL prefsum(int x) {
    x++;
    LL res = 0;
    int v = 1;
    int l = 0, r = MAXN-1;
    while (v < MAXN) {
        deflag(v);
        int m = (l+r)/2;
        if (x <= m) {
            v = 2*v;
            r = m;
        } else {
            res += ss[2*v];
            v = 2*v + 1;
            l = m+1;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N, Q;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        mm[MAXN+i] = a;
        ss[MAXN+i] = a;
    }
    for (int i = MAXN-1; i >= 1; i--) {
        mm[i] = mm[2*i+1];
        ss[i] = ss[2*i] + ss[2*i+1];
    }

    // cout << FirstLeq(4) << endl;
    // return 0;

    for (int q = 0; q < Q; q++) {
        int t, x;
        LL y;
        cin >> t >> x >> y;
        x--;
        if (t == 1) {
            int pos = FirstLeq(y);
            if (x < pos) continue;
            update(1, 0, MAXN-1, pos, x, y);
        } else {
            int pos = x;
            LL money = y;
            int ans = 0;
            while (money > 0 and pos < N) {
                pos = max(pos, FirstLeq(money));
                if (pos >= N) break;
                LL presum = 0;
                if (pos > 0) presum = prefsum(pos-1);
                int last_pos = FirstGreaterPref(money + presum);
                last_pos--;
                last_pos = min(last_pos, N-1);

                ans += last_pos-pos + 1;
                money -= prefsum(last_pos) - presum;
                pos = last_pos+1;
            }
            cout << ans << "\n";
        }
    }
}