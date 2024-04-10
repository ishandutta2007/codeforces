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

const int mod = 31607;
const int den = 3973; 
const int MAXN = 21;
int n;
int a[MAXN][MAXN];

int prodrow[MAXN];
int prodcol[MAXN];
int memo_prodcol[MAXN][MAXN];


// Complexity: O(n2^n), with rather small constant factor.
int dfs(int row) {
    if (row == n) {
        int res = 1;
        for (int i = 0; i < n; i++) res = res * (1-prodcol[i]) % mod;
        return res;
    }
    for (int i = 0; i < n; i++) {
        memo_prodcol[row][i] = prodcol[i];
        prodcol[i] = prodcol[i] * a[row][i] % mod;
    }
    int ris0 = dfs(row+1);
    for (int i = 0; i < n; i++) prodcol[i] = memo_prodcol[row][i];
    int ris1 = prodrow[row] * dfs(row+1) % mod;
    return (ris0 - ris1) % mod;
}

int solve() {
    for (int i = 0; i < n; i++) {
        prodrow[i] = 1;
        prodcol[i] = 1;
        for (int j = 0; j < n; j++) prodrow[i] = prodrow[i] * a[i][j] % mod;
    }
    return dfs(0);
}

int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        a[i][j] = a[i][j] * den % mod;
    }

    vector<int> diag(n);
    vector<int> antidiag(n);
    for (int i = 0; i < n; i++) {
        diag[i] = a[i][i];
        antidiag[i] = a[i][n-1-i];
    }
    int res0 = solve();
    
    int res1 = -1;
    for (int i = 0; i < n; i++) res1 = res1 * a[i][i] % mod, a[i][i] = 1;
    res1 = res1 * solve() % mod;
    for (int i = 0; i < n; i++) a[i][i] = diag[i];
    
    int res2 = -1;
    for (int i = 0; i < n; i++) res2 = res2 * a[i][n-1-i] % mod, a[i][n-1-i] = 1;
    res2 = res2 * solve() % mod;
    for (int i = 0; i < n; i++) a[i][n-1-i] = antidiag[i];

    int res3 = 1;
    for (int i = 0; i < n; i++) {
        res3 = res3 * a[i][i] % mod, a[i][i] = 1;
        res3 = res3 * a[i][n-1-i] % mod, a[i][n-1-i] = 1;
    }
    res3 = res3 * solve() % mod;

    // dbg(res0, res1, res2, res3);

    int res = 1-(res0+res1+res2+res3);
    res %= mod;
    if (res < 0) res += mod;

    cout <<  res << "\n";
}