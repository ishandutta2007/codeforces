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

struct PP {
    LL m, M;
    PP(): m(1e18), M(-1e18) {}
    PP(LL m, LL M): m(m), M(M) {}
};


const int MAXN = 1<<18;
PP ff[2*MAXN];


PP Join(PP A, PP B) {
    return {min(A.m, B.m), max(A.M, B.M)};
}

PP query(int v, int l, int r, int a, int b) {
    if (r < a or b < l) return PP();
    if (a <= l and r <= b) return ff[v];
    int m = (l+r)/2;
    return Join(query(2*v, l, m, a, b), query(2*v+1, m+1, r, a, b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, q;
    cin >> n >> q;
    vector<LL> diff(n+1);
    for (int i = 1; i <= n; i++) {
        LL a;
        cin >> a;
        diff[i] -= a;
    }
    for (int i = 1; i <= n; i++) {
        LL b;
        cin >> b;
        diff[i] += b;
    }
    ff[MAXN].m = 0, ff[MAXN].M = 0;
    for (int i = 1; i <= n; i++) {
        ff[MAXN+i].M = ff[MAXN+i].m = ff[MAXN+i-1].m + diff[i];
    }
    for (int i = MAXN-1; i >= 1; i--) {
        ff[i] = Join(ff[2*i], ff[2*i+1]);
    }
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        LL p = ff[MAXN+l-1].m;
        LL q = ff[MAXN+r].m;
        if (p != q) {
            cout << -1 << "\n";
            continue;
        }
        PP ans = query(1, 0, MAXN-1, l, r);
        // dbg(p, ans.m, ans.M);
        if (ans.m < p) cout << -1 << "\n";
        else cout << ans.M-p << "\n";
    }
}