#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC target ("sse4.2")

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

// Fast exponentiation modulo mod. Returns x**e modulo mod.
// Assumptions: 0 <= x < m
//              mod < 2**31.
//              0 <= e < 2**63
LL pow(LL x, LL e, LL mod) {
    LL res = 1;
    for (; e >= 1; e >>= 1) {
        if (e & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}


int k = 0;
LL pot[100];
LL val[100];
const int mod = 998244353;

void add(LL x) {
    for (int i = 0; i < k; i++) {
        if (pot[i]&x) x ^= val[i];
    }
    if (x != 0) {
        pot[k] = 1;
        val[k] = x;
        while ((pot[k]&x) == 0) pot[k] <<= 1;
        k++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        LL x;
        cin >> x;
        add(x);
    }
    // dbg(M-k);
    dbg(k);
    if (k <= 31) {
        // vector<LL> poss(1<<k, 0);
        // for (int i = 0; i < k; i++) {
            // int z = 1<<i;
            // for (int j = 0; j < z; j++) poss[z+j] = poss[j]^val[i];
        // }
        int k1 = k/2;
        int k2 = k-k1;
        vector<LL> vec1(1<<k1);
        vector<LL> vec2(1<<k2);
        for (int i = 0; i < k1; i++) {
            int z = 1<<i;
            for (int j = 0; j < z; j++) vec1[z+j] = vec1[j]^val[i];
        }
        for (int i = 0; i < k2; i++) {
            int z = 1<<i;
            for (int j = 0; j < z; j++) vec2[z+j] = vec2[j]^val[i+k1];
        }
        vector<LL> res(M+1, 0);
        for (LL x: vec1) for (LL y: vec2) res[__builtin_popcountll(x^y)]++;
        for (int i = 0; i <= M; i++) cout << res[i] * pow(2, N-k, mod) % mod << " ";
        cout << "\n";
    } else {
        for (int i = 0; i < k; i++) for (int j = 0; j < i; j++) {
            if (val[j]&pot[i]) val[j] ^= val[i];
        }
        vector<int> suff(k, 0);
        LL mm = 0;
        for (int i = 0; i < k; i++) mm ^= pot[i];
        for (int i = 0; i < k; i++) {
            int cnt = 0;
            for (int j = 0; j < M; j++) {
                if ((mm&(1ll<<j)) == 0) {
                    if (val[i]&(1ll<<j)) suff[i] ^= 1<<cnt;
                    cnt++;
                }
            }
        }
        // dbg(suff, val[0], val[1], val[2]);
        vector<vector<int>> poss(k-1, vector<int>(1<<(M-k), 0));
        for (int i = 0; i < k; i++) {
            for (int s = i-2; s >= 0; s--) {
                for (int x = 0; x < (1<<(M-k)); x++) {
                    int& w = poss[s+1][x];
                    w += poss[s][x^suff[i]];
                    w = (w>mod)?(w-mod):w;
                }
            }
            // poss[0][suff[i]]++;
            for (int j = 0; j < i; j++) poss[0][suff[i]^suff[j]]++;
        }
        vector<LL> res(M+1);
        res[0] = 1;
        for (int i = 0; i < k; i++) res[__builtin_popcountll(suff[i])+1]++;
        for (int s = 0; s < k-1; s++) {
            for (int x = 0; x < (1<<(M-k)); x++) {
                int z = s + __builtin_popcountll(x) + 2;
                res[z] = (res[z] + poss[s][x]) % mod;
            }
        }

        for (int i = 0; i <= M; i++) cout << res[i] * pow(2, N-k, mod) % mod << " ";
        cout << "\n";
    }
    
}