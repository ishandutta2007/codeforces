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

// const int MAXD = 5010;
const int MAXN = 100100;
int mu[MAXN];
LL prefmu[MAXN];
bool iscomp[MAXN];
LL q[MAXN];
LL prefq[MAXN];

// LL inter(int l, int r) {
    // int m = r%l;
    // int t = r/l;
    // return l*prefq[t-1] + (m+1)*q[t];
// }

LL fast_inter(int x, int y) {
    LL res = 0;
    // for (int i = y; i <= x; i++) res += q[x/i];
    for (int i = y; i <= x; i++) {
        int z = x/i;
        int j = x/z;
        res += (j-i+1)*q[z];
        i = j;
    }
    return res;
}

void dc(const vector<LL>& cost, vector<LL>& f, int l, int r, int a, int b) {
    if (r < l) return;
    int m = (l+r)/2;
    LL best = 1e18;
    int bm = min(b, m);
    int c = -1;
    LL inter = fast_inter(m, bm); // TODO q[m/m] + q[m/(m-1)] + .. + q[m/bm] 
    for (int z = bm; z >= a; z--) {
        LL maybe = cost[z-1] + inter;
        if (maybe < best) {
            best = maybe;
            c = z;
        }
        if (z > 1) inter += q[m/(z-1)];
    }
    f[m] = best;
    // dbg(l, r, a, b, m, best, inter);

    dc(cost, f, l, m-1, a, c);
    dc(cost, f, m+1, r, c, b);
}

const int MAXK = 20;
// const int MAXN = 100010;
LL ans[MAXK][MAXN];

void solve() {
    int n = 100000;
    vector<LL> din(n+1, 1e18);
    din[0] = 0;
    // for (int i = 1; i <= n; i++) din[i] = inter(1, i);
    for (int k = 1; k < MAXK; k++) {
        vector<LL> new_din(n+1);
        dc(din, new_din, 1, n, 1, n);
        // dbg(k, din, new_din);
        din = new_din;
        for (int i = 1; i <= n; i++) ans[k][i] = din[i];
    }
    // cout << din[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    for (int i = 1; i < MAXN; i++) mu[i] = 1;
    for (int p = 2; p < MAXN; p++) {
        if (iscomp[p]) continue;
        for (int i = 2*p; i < MAXN; i += p) iscomp[i] = true;
        for (int i = p; i < MAXN; i += p) mu[i] = -mu[i];
        for (LL i = ((LL)p)*p; i < MAXN; i += p*p) mu[i] = 0;
    }
    // return 0;
    // return 0;
    for (int i = 1; i < MAXN; i++) prefmu[i] = prefmu[i-1] + mu[i];
    // cout << mu[4] << " " << mu[5] << " " << mu[6] << endl;
    for (int n = 1; n < MAXN; n++) {
        for (int d = 1; d <= n; d++) {
            LL z = n/d;
            LL e = n/z;
            q[n] += (prefmu[e]-prefmu[d-1]) * (z*(z+1))/2;
            d = e;
        }
    }
    
    for (int i = 1; i < MAXN; i++) prefq[i] = prefq[i-1] + q[i];
    // cout << q[1] << " " << q[2] << " " << q[3] << " " << q[4] << endl;

    solve();

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k;
        cin >> n >> k;
        if (k >= MAXK) cout << n << "\n";
        else cout << ans[k][n] << "\n";
    }
}