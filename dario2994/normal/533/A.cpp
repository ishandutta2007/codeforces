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

const int MAXN = 1<<20;
int h[MAXN];
int s[MAXN];
vector<int> aa[MAXN];

int no_boss[MAXN];
int path[MAXN];
vector<int> groups[MAXN];
void dfs(int v, int p, int g) {
    if (v != 0) {
        if (h[g] > h[v]) {
            no_boss[v] = h[g];
            g = v;
        } else no_boss[v] = min(no_boss[p], h[v]);
    }
    path[v] = min(path[v], h[v]);
    
    groups[g].push_back(v);
    for (int a: aa[v]) {
        if (a == p) continue;
        path[a] = path[v];
        dfs(a, v, g);
    }
}

int tree_sum[2*MAXN];
int tree_suff[2*MAXN];

void add(int v, int val) {
    v += MAXN;
    tree_sum[v] += val;
    tree_suff[v] = min(0, tree_sum[v]);
    while (v > 1) {
        v >>= 1;
        tree_sum[v] = tree_sum[2*v] + tree_sum[2*v+1];
        tree_suff[v] = min(tree_suff[2*v+1], tree_sum[2*v+1] + tree_suff[2*v]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    vector<int> coord;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> h[i], coord.push_back(h[i]);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        aa[u].push_back(v);
        aa[v].push_back(u);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) cin >> s[i], coord.push_back(s[i]);

    const int INF = 1e9 +1;
    coord.push_back(INF);
    sort(coord.begin(), coord.end());
    coord.erase(unique(coord.begin(), coord.end()), coord.end());
    auto compress_coord = [&](int x) {
        return lower_bound(coord.begin(), coord.end(), x)-coord.begin();
    };
    for (int i = 0; i < n; i++) h[i] = compress_coord(h[i]);
    for (int i = 0; i < k; i++) s[i] = compress_coord(s[i]);

    for (int i = 0; i < k; i++) add(s[i], -1);

    path[0] = compress_coord(INF);
    no_boss[0] = compress_coord(INF);
    dfs(0, -1, 0);
    for (int i = 0; i < n; i++) add(path[i], 1);

    if (tree_suff[1] >= 0) {
        cout << 0 << "\n";
        return 0;
    }
    int i0 = MAXN-1;
    int sum = 0;
    while (sum >= 0) {
        i0--;
        sum += tree_sum[MAXN+i0];
    }

    // for (int i = 0; i < n; i++) cout << h[i] << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++) cout << path[i] << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++) cout << no_boss[i] << " ";
    // cout << endl;
    // for (int i = 0; i < k; i++) cout << s[i] << " ";
    // cout << endl;

    // We have to try and set the value to i0.
    int res = 1e9 + 10;
    for (int g = 0; g < n; g++) {
        if (groups[g].empty()) continue;
        for (int v: groups[g]) add(path[v], -1);
        for (int v: groups[g]) add(min(no_boss[v], i0), 1);
        if (tree_suff[1] >= 0) 
            res = min(res, coord[i0] - coord[h[groups[g][0]]]);
        for (int v: groups[g]) add(min(no_boss[v], i0), -1);
        for (int v: groups[g]) add(path[v], 1);
    }
    if (res >= 1e9) cout << -1 << "\n";
    else cout << res << "\n";
}