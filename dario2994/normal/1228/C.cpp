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
// Assumptions: 0 <= x < mod
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    LL N, X;
    cin >> X >> N;
    vector<LL> primes;
    for (LL p = 2; p*p <= X; p++) {
        if (X%p == 0) {
            primes.push_back(p);
            while (X%p == 0) X /= p;
        }
    }
    if (X > 1) primes.push_back(X);
    // dbg(primes);
    const LL mod = 1e9 + 7;
    LL res = 1;
    for (LL p: primes) {
        LL esp = 0;
        LL Q = N;
        for (int e = 1; e < 100; e++) {
            Q /= p;
            esp += Q;
            // res *= pow(e, (Q-Q/p), mod);
            // res %= mod;
        }
        res = res * pow(p, esp, mod) % mod;
    }
    cout << res << "\n";
}