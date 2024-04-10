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

const int MAXN = 101000;

LL compute_max(LL N, LL K) {
    return N*(N+1)/2;
}


map<pair<LL, LL>, LL> memo;
LL compute_min(LL N, LL K) {
    if (N == 0) return 0;
    if (K == 1) return compute_max(N, K);
    pair<LL, LL> pp = {N, K};
    if (!memo.count(pp)) {
        if (N-1 <= K) return 2*N-1;
        LL c = (N-1)/K;
        LL m = (N-1) % K;
        if (m == 0) memo[pp] = N + K*compute_min(c, K);
        else memo[pp] = N + m * compute_min(c+1, K) + (K-m)*compute_min(c, K);
    }
    return memo[pp];
}

int p[MAXN];
void solve(LL N, LL K, LL S, int a, int b) {
    if (N == 0) return;
    // dbg(N, K, S, a, b);
    // assert(compute_min(N, K) <= S and S <= compute_max(N, K));

    S -= N;
    N--;
    int A = a;
    a++;
    LL sz = N;
    for (int i = 0; i < K-1 and N > 0; i++) { // SKIPPING THE LAST ONE
        sz = min(N, sz);
        while (sz > 0) {
            LL c = (N-sz)/(K-i-1);
            LL m1 = (N-sz) % (K-i-1);
            LL m2 = K-i-1-m1;
            LL low1 = compute_min(c+1, K);
            LL low2 = compute_min(c, K);
            // dbg(sz, c, m1, m2, low1, low2);
            if (compute_min(sz, K) + low1 * m1 + low2*m2 <= S) {
                LL val = min(compute_max(sz, K), S - low1 * m1 - low2*m2);
                // assert(val >= compute_min(sz, K));
                S -= val;
                p[a] = A;
                // dbg(sz, K, val);
                solve(sz, K, val, a, a+sz-1);
                a += sz;
                N -= sz;
                break;
            }
            sz--;
        }
    }
    if (N > 0) {
        p[a] = A;
        solve(N, K, S, a, b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    LL N, S;
    cin >> N >> S;
    if (S < 2*N-1 or N*(N+1)/2 < S) {
        cout << "No\n";
        return 0;
    }
    for (LL K = 1; K <= N-1; K++) {
        if (compute_min(N, K) <= S) {
            // dbg(K);
            solve(N, K, S, 1, N);
            break;
        }
    }
    cout << "Yes\n";
    for (int i = 2; i <= N; i++) {
        cout << p[i] << " ";
    }
    cout << "\n";

    // for (int i = 5; i <= 10; i++) {
    //     int M = compute_max(i, 0);
    //     int m = compute_min(i, i);
    //     for (int j = m; j <= M; j++) solve_problem(i, j);
    // }
}