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

LL Inverse(LL n, LL m) {
    n %= m;
    if (n <= 1) return n; // Handles properly (n = 0, m = 1).
    return m - ((m * Inverse(m, n) - 1) / n);
}

const LL mod = 1e9 + 7;
LL Z;
const int MAXN = 1e6 + 10;
LL invpow[MAXN];

LL get_sub(const vector<LL>& hh, int a, int b) {
    return (((hh[b+1]-hh[a])*invpow[a] % mod) + mod) % mod;
}

void solve() {
    string S;
    cin >> S;
    int N = S.size();
    int it = 0;
    while (it < N-it-1 and S[it] == S[N-it-1]) it++;
    string T;
    for (int i = it; i < N-it; i++) T += S[i];
    string res = "";
    for (int i = 0; i < it; i++) res += S[i];
    N = T.size();
    // dbg(N, T);

    vector<LL> hh(N+1, 0);
    vector<LL> hh_rev(N+1, 0);
    LL pot = 1;
    for (int i = 0; i < N; i++) {
        hh[i+1] = (hh[i] + pot * (T[i]-'a')) % mod;
        hh_rev[i+1] = (hh_rev[i] + pot * (T[N-1-i]-'a')) % mod;
        pot = pot * Z % mod;
    }
    // dbg(hh, hh_rev);

    int pos = -1;
    for (int i = 0; i < N; i++) {
        if (get_sub(hh, 0, i) == get_sub(hh_rev, N-i-1, N-1)) pos = i;
    }
    int pos_rev = -1;
    for (int i = 0; i < N; i++) {
        if (get_sub(hh_rev, 0, i) == get_sub(hh, N-i-1, N-1)) pos_rev = i;
    }
    cout << res;
    // dbg(pos, pos_rev, Z);
    if (max(pos, pos_rev) >= 0) {
        if (pos >= pos_rev) {
            for (int i = 0; i <= pos; i++) cout << T[i];
        } else {
            for (int i = N-pos_rev-1; i < N; i++) cout << T[i];
        }
    }
    reverse(res.begin(), res.end());
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    srand(time(NULL));
    Z = 2*(30 + (rand() % 100)) + 1;
    // Z = 147;
    invpow[0] = 1;
    invpow[1] = Inverse(Z, mod);
    for (int i = 2; i < MAXN; i++) invpow[i] = invpow[i-1] * invpow[1] % mod;

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}