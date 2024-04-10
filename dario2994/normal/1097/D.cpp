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

const int MAXN = -1;

LL mod = 1e9 + 7;

LL Inverse(LL n, LL m) {
    n %= m;
    if (n <= 1) return n; // Handles properly (n = 0, m = 1).
    return m - ((m * Inverse(m, n) - 1) / n);
}

vector<LL> comp_prob(int e, int k) {
    vector<LL> res(e+1, 0);
    res[e] = 1;
    for (int i = 0; i < k; i++) {
        for (int f = 0; f <= e; f++) res[f] = res[f] * Inverse(f+1, mod) % mod;
        for (int f = e-1; f >= 0; f--) res[f] = (res[f] + res[f+1]) % mod;
    }
    return res;
}

LL solve(const vector<pair<LL, int>>& fact, const vector<vector<LL>>& probs, LL num, LL prob, int it) {
    if (it == SZ(fact)) {
        // dbg(num);
        // dbg(prob);
        return (num % mod) * prob %mod;
    }
    LL res = 0;
    for (int i = 0; i <= fact[it].second; i++) {
        res += solve(fact, probs, num, prob * probs[it][i] % mod, it+1);
        num *= fact[it].first;
    }

    return res % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    LL N;
    cin >> N;
    int K;
    cin >> K;
    vector<pair<LL, int>> fact;
    vector<vector<LL>> probs;
    for (LL d = 2; d*d <= N; d++) {
        if (N % d) continue;
        int e = 0;
        while (N % d == 0) e++, N /= d;
        fact.push_back({d, e});
        probs.push_back(comp_prob(e, K));
    }
    if (N != 1) {
        fact.push_back({N, 1});
        probs.push_back(comp_prob(1, K));
    }
    // dbg(fact);
    // dbg(probs);
    LL res = solve(fact, probs, 1, 1, 0);
    cout << res << "\n";
}