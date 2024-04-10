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

const int MAXN = 1010;
const LL mod = 1e9 + 7;
LL binom[MAXN][MAXN];
int din[MAXN];
LL suff[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    for (int n = 0; n < MAXN; n++) {
        binom[n][0] = binom[n][n] = 1;
        for (int k = 1; k < n; k++) {
            binom[n][k] = (binom[n-1][k] + binom[n-1][k-1]) % mod;
        }
    }
    din[1] = 0;
    for (int n = 2; n < MAXN; n++) {
        din[n] = 1 + din[__builtin_popcount(n)];
    }
    string S;
    cin >> S;
    int N = S.size();
    for (int s = N; s >= 0; s--) {
        suff[s][0] = 1;
        for (int k = 1; k <= N-s; k++) {
            if (S[s] == '0') suff[s][k] = suff[s+1][k];
            else suff[s][k] = (suff[s+1][k-1] + binom[N-1-s][k]) % mod;
        }
    }
    int K;
    cin >> K;
    if (K == 0) {
        cout << 1 << "\n";
        return 0;
    }
    
    LL ans = 0;
    for (int i = 1; i <= N; i++) if (din[i] == K-1) ans += suff[0][i];
    if (K == 1) ans += mod-1;
    cout << ans % mod << "\n";

    // LL val = 0;
    // for (char c : S) {
        // val *= 2;
        // if (c == '1') val++;
    // }
    // int correct = 0;
    // for (int i = 1; i <= val; i++) {
        // int it = i;
        // int cc = 0;
        // while (it != 1) it = __builtin_popcount(it), cc++;
        // if (cc == K) correct++;
    // }
    // cout << correct << endl;
    // assert(correct == ans);
}