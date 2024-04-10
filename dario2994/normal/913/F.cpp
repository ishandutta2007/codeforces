#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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

template <typename Container>
int SZ(const Container& S) { return S.size(); }

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 2010;
const LL mod = 998244353;

LL pot(LL a, LL e) {
    if (e == 0) return 1;
    if (e&1) return (a*pot((a*a)%mod, e/2)) % mod;
    return pot((a*a)%mod, e/2);
}

LL inv(LL n, LL m) {
    if (n == 1) return 1;
    if (n == -1) return -1;
    LL y = inv(m % n, n);
    return m - ((m * y - 1) / n) % m;
}

LL potc[MAXN*MAXN], potc2[MAXN*MAXN], potc3[MAXN*MAXN], potc4[MAXN*MAXN];
LL ss[MAXN][MAXN];
LL aa[MAXN][MAXN];
LL res[MAXN];

LL bin(LL k) {
    return (k*(k-1)) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    int a, b;
    cin >> a >> b;
    LL p = (a*inv(b, mod)) % mod;
    
    LL c = (p*inv(1-p, mod)) % mod;
    LL c2 = 1-p;
    LL c3 = inv(p, mod);
    LL c4 = inv(1-p, mod);
    potc[0] = potc2[0] = potc3[0] = potc4[0] = 1;
    for (int n = 1; n <= N*N; n++) {
        potc[n] = (potc[n-1]*c) % mod;
        potc2[n] = (potc2[n-1]*c2) % mod;
        potc3[n] = (potc3[n-1]*c3) % mod;
        potc4[n] = (potc4[n-1]*c4) % mod;
        // cout << n << " potc: " << potc[n] << " " << potc2[n] << " " << potc3[n] << endl;
    }

    for (int n = 0; n <= N; n++) {
        ss[0][n] = 1;
        for (int k = 1; k <= n; k++) ss[k][n] = (ss[k][n-1] + potc[n]*ss[k-1][n-1]) % mod;
    }
    for (int n = 1; n <= N; n++) {
        for (int k = 1; k <= n-1; k++) {
            aa[k][n] = (((aa[k][k]*potc2[k*n]) % mod) * ((ss[k][n]*((potc4[bin(k)]*potc3[bin(k+1)]) % mod)) % mod)) % mod;
            // cout << k << " " << n << " " << aa[k][n] << endl;
        }
        aa[n][n] = 1;
        for (int k = 1; k <= n-1; k++) aa[n][n] -= aa[k][n];
        aa[n][n] %= mod;
    }
    for (int n = 2; n <= N; n++) {
        res[n] = bin(n);
        for (int k = 1; k <= n-1; k++) res[n] += (aa[k][n]*(res[k] + res[n-k] - bin(n-k))) % mod;
        res[n] %= mod;
        // cout << n << " " << aa[n][n] << endl;
        res[n] *= inv(1-aa[n][n], mod);
        res[n] %= mod;
    }
    cout << (res[N] + mod) % mod << "\n";
}