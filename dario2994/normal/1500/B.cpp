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

LL Inverse(LL n, LL m) {
    n %= m;
    if (n <= 1) return n; // Handles properly (n = 0, m = 1).
    return m - ((m * Inverse(m, n) - 1) / n);
}


// Returns the largest number m that divides n such that it has only primes
// that divide d.
// The complexity is logarithmic (computing efficiently gcd(d^100,n)).
//
// Assumptions: d | n
//              d < 1<<31.
//              "returned value" < 1<<31 (true if n < 1<<31)
LL CommonPart(LL d, LL n) {
    LL x = d;
    LL y = 1;
    while (x != y) {
        y = x;
        x = __gcd(x*x, n);
    }
    return x;
}

// Returns an x (with absolute value below mn) such that m|x-a and n|x-b.
//
// Assumptions: m, n coprimes.
//              mn, n < 1<<62
//
// ACHTUNG: The returned value might be negative.
LL CrtInternal(LL a, LL m, LL b, LL n) {
    a %= m, b %= n;
    LL inv = Inverse(m, n);
    LL x = a + m * (inv*(b-a) % n);
    return x%(m*n);
}

// Returns the solution to the given system of modular equation.
// The system is given as a vector of pair <value, modulo>.
// The result is a pair <value, modulo> with 0 <= value < modulo.
// If there is no solution the returned pair is {0, 0}.
//
// Assumptions: The lcm of the modulos must be below 2**31.
//
// ACHTUNG: To handle modulos with lcm > 2**31, use __int128.
pair<LL, LL> SolveRemainderSystem(const vector<pair<LL, LL>>& system) {
    if (system.empty()) return {0, 1};
    LL m = system[0].second;
    LL a = system[0].first % m;
    
    for (int i = 1; i < (int)system.size(); i++) {
        LL n = system[i].second;
        LL b = system[i].first % n;

        LL g = __gcd(m, n);
        if (g != 1) {
            if ((a-b)%g != 0) return {0, 0};
            LL m2 = CommonPart(m/g, m); // a
            LL n2 = CommonPart(n/g, n); // b
            LL z = g / (__gcd(g, m2) * __gcd(g, n2));
            a = CrtInternal(CrtInternal(a%m2, m2, b%n2, n2), m2*n2, a%z, z);
            m = m2*n2*z;
        } else {
            a = CrtInternal(a, m, b, n);
            m = m * n;
        }
    }
    if (a < 0) a += m;
    return {a, m};
}

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N, M;
    LL K;
    cin >> N >> M >> K;

    map<int,int> val2id;
    vector<int> A(N);
    vector<int> B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i], val2id[B[i]] = i;

    
    vector<pair<LL,LL>> ord(N); 
    for (int i = 0; i < N; i++) {
        if (!val2id.count(A[i])) continue;
        int j = val2id[A[i]];
        ord[i] = SolveRemainderSystem({pair<LL,LL>{i, N}, pair<LL,LL>{j, M}});
    }

    LL l = 1;
    LL r = 1e18;
    while (l != r) {
        LL z = (l+r)/2;
        LL cnt = z;
        for (int i = 0; i < N; i++) {
            if (ord[i].second == 0) continue;
            LL a = z/ord[i].second;
            LL b = z - a*ord[i].second;
            cnt -= a + (b > ord[i].first);
        }
        if (cnt >= K) r = z;
        else l = z+1;
    }
    cout << l << "\n";
}