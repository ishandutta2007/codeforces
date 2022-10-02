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

const int MAXN = 30100;
int n;
int warrior_pos_inv[MAXN];
int horse_pos_inv[MAXN];
int warrior_pos[MAXN];
int horse_pos[MAXN];

LL A[MAXN];
LL B[MAXN];
int x[MAXN];

LL din[MAXN];
LL solve() {
    const LL INF = 1e17;
    din[n+1] = -INF, din[n+2] = -INF;
    din[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        din[i] = -INF;
        auto f = [i](LL z, int k) { din[i] = max(din[i], z + din[i+k]); };
        if (x[i] != i) f(A[i]*B[i], 1);
        if (x[i] != i+1 and x[i+1] != i) f(A[i]*B[i+1] + A[i+1]*B[i], 2);
        if (x[i] != i+2 and x[i+1] != i and x[i+2] != i+1)
            f(A[i]*B[i+2] + A[i+1]*B[i] + A[i+2]*B[i+1], 3);
        if (x[i] != i+1 and x[i+1] != i+2 and x[i+2] != i)
            f(A[i]*B[i+1] + A[i+1]*B[i+2] + A[i+2]*B[i], 3);
    }
    return din[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];
    for (int i = 0; i < n; i++) warrior_pos_inv[i] = i, horse_pos_inv[i] = i;
    sort(warrior_pos_inv, warrior_pos_inv+n, [&](int x, int y) { return A[x] < A[y];});
    sort(horse_pos_inv, horse_pos_inv+n, [&](int x, int y) { return B[x] < B[y];});
    sort(A, A+n);
    sort(B, B+n);
    for (int i = 0; i < n; i++) {
        warrior_pos[warrior_pos_inv[i]] = i;
        horse_pos[horse_pos_inv[i]] = i;
    }
    for (int i = 0; i < n; i++) x[warrior_pos[i]] = horse_pos[i];
    // dbg_arr(A, n);
    // dbg_arr(B, n);
    // dbg_arr(x, n);

    // cout << solve() << "\n";
    // return 0;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        a = warrior_pos[a], b = warrior_pos[b];
        swap(x[a], x[b]);
        cout << solve() << "\n";
    }
}