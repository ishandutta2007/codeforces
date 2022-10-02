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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXK = 30;
int fib[MAXK];

const int MAXN = 201000;
vector<int> aa[MAXN];
bool removed[MAXN];

bool check(int v, int k);

int weight[MAXN];
// root of k-1, root of k-2
pair<int,int> dfs(int v, int f, int k) {
    weight[v] = 1;
    for (int a: aa[v]) {
        if (removed[a] or a == f) continue;
        auto pp = dfs(a, v, k);
        if (pp.first != 0) return pp;
        weight[v] += weight[a];
    }
    if (weight[v] == fib[k-1]) return {v, f};
    if (weight[v] == fib[k-2]) return {f, v};
    return {0, 0};
}

bool check(int v, int k) {
    if (fib[k] <= 3) return true;

    auto pp = dfs(v, 0, k);
    if (pp.first == 0) return false;

    removed[pp.first] = true;
    bool ans1 = check(pp.second, k-2);
    removed[pp.first] = false;
    removed[pp.second] = true;
    bool ans2 = check(pp.first, k-1);
    removed[pp.second] = false;
    
    return ans1 and ans2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    fib[0] = 1, fib[1] = 1;
    for (int i = 2; i < MAXK; i++) fib[i] = fib[i-1] + fib[i-2];
    // cout << fib[MAXK-1] << endl;

    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        aa[u].push_back(v);
        aa[v].push_back(u);
    }
    if (n <= 3) {
        cout << "YES\n";
        return 0;
    }
    for (int i = 2; i < MAXK; i++) {
        if (n == fib[i]) {
            if (check(1, i)) cout << "YES\n";
            else cout << "NO\n";
            return 0;
        }
    }
    cout << "NO\n";
}