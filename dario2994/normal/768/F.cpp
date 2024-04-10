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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) cout << #x  << ": " << x << endl;
    #define dbg_vec(x) cout << #x << ": " << print_iterable(x.begin(), x.end(), -1) << endl;
    #define dbg_array(x, len) cout << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x) 
    #define dbg_vec(x)
    #define dbg_array(x, len)
#endif  

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const LL mod = 1e9+7;
const LL MAXN = 100100;
LL fact[MAXN];
LL inv_fact[MAXN];

//Return the inverse of n modulo m. (doesn't check whether they are coprime)
//inverse(5, 9)= 2; inverse(3, 16)= 11
LL inverse(LL n, LL m) {
	if (n == 1) return 1;
	LL y = inverse(m%n, n);
	return m-((m*y-1)/n)%m;
}


LL inv(LL x) {
    return inverse(x, mod);
}

void PrecomputeFact() {
    fact[0] = 1;
    inv_fact[0] = 1;
    for (LL i = 1; i < MAXN; i++) {
        fact[i] = (fact[i-1] * (LL)i) % mod;
        inv_fact[i] = (inv_fact[i-1] * (LL)inv(i)) % mod;
    }
}

LL ComputeBinomial(LL n, LL k) {
    if (k > n) return 0;
    LL res = fact[n];
    res = (res * inv_fact[k]) % mod;
    res = (res * inv_fact[n-k]) % mod;
    return res;
}

LL simple(LL n, LL k) {
    if (k < 0) return 0;
    if (k == 0) {
        return n == 0;
    }
    return ComputeBinomial(n-1, k-1);
}

LL nice(LL n, LL k, LL h) {
    if (k < 0) return 0;
    if (k == 0) {
        return n == 0;
    }
    return ComputeBinomial(n+k-1-(h+1)*k, k-1);
}

int main() {
    ios::sync_with_stdio(false);
    PrecomputeFact();
    LL f, w, h;
    cin >> f >> w >> h;
    LL p = 0;
    LL q = 0;
    for (int k = 0; k <= f; k++) {
        LL p_tmp = nice(w, k+1, h) + nice(w, k-1, h) + 2ll * nice(w, k, h);
        LL q_tmp = simple(w, k+1) + simple(w, k-1) + 2ll * simple(w, k);
        p_tmp %= mod;
        q_tmp %= mod;
        p += (simple(f, k) * (p_tmp)) % mod;
        q += (simple(f, k) * (q_tmp)) % mod;
        p %= mod;
        q %= mod;
    }
    cout << (p * inv(q)) % mod;
}