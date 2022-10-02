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

const LL mod = 1e9 + 7;
LL Inverse(LL n, LL m) {
	if (n == 1) return 1;
	LL y = Inverse(m % n, n);
	return m - ((m * y - 1) / n) % m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    LL N, K;
    cin >> N >> K;
    vector<LL> ans(N);
    ans[0] = 1;
    LL curr_sum = 1;
    for (int n = 1; n < N; n++) {
        ans[n] = (curr_sum * Inverse(n, mod)) % mod;
        curr_sum += ans[n];
        if (n >= K) curr_sum += mod - ans[n-K];
        curr_sum %= mod;
    }
    vector<LL> fact(N+1);
    fact[0] = 1;
    for (LL i = 1; i <= N; i++) fact[i] = (fact[i-1]*i) % mod;

    LL ans_sum = 0;
    for (int p = 0; p < N; p++) ans_sum += ans[p];
    ans_sum %= mod;
    ans_sum *= fact[N-1];
    ans_sum %= mod;
    cout << (fact[N] + mod - ans_sum) % mod << "\n";
}