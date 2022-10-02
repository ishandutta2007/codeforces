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

const int MAXN = 200100;
LL din[MAXN][2];
LL l[MAXN], r[MAXN];
vector<int> aa[MAXN];

void dfs(int v, int f) {
    LL res0 = 0, res1 = 0;
    for (int a: aa[v]) {
        if (a == f) continue;
        dfs(a, v);
        res0 += din[a][0];
        res1 += din[a][1];
    }
    if (f != 0) {
        din[v][0] = max(res0 + llabs(l[f] - l[v]), res1 + llabs(l[f] - r[v]));
        din[v][1] = max(res0 + llabs(r[f] - l[v]), res1 + llabs(r[f] - r[v]));
    } else {
        din[v][0] = max(res0, res1);
    }
}

void solve() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) aa[i].clear();
    for (int v = 1; v <= N; v++) cin >> l[v] >> r[v];
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        aa[u].push_back(v);
        aa[v].push_back(u);
    }
    dfs(1, 0);
    cout << din[1][0] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) solve();
}