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

const LL INF = 1e14;
const int MAXN = 610;
LL aa[MAXN][MAXN];
int n;

vector<LL> dijkstra(int source) {
    vector<LL> dist(n+1, INF);
    
    vector<bool> used(n+1, false);
    dist[source] = 0;
    for (int it = 0; it <= n; it++) {
        int v = -1;
        for (int i = 0; i <= n; i++) {
            if (!used[i] and (v == -1 or dist[v] > dist[i])) v = i;
        }
        used[v] = true;
        for (int a = 0; a <= n; a++) {
            LL d = dist[v] + aa[v][a];
            dist[a] = min(dist[a], d);
        }
    }
    return dist;
}

vector<pair<int,LL>> queries[MAXN];
bool ans[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) aa[i][j] = INF;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        aa[u][v] = w;
        aa[v][u] = w;
    }

    int q;
    cin >> q;

    
    
    for (int i = 0; i < q; i++) {
        int u, v;
        LL l;
        cin >> u >> v >> l;
        if (u > v) swap(u, v);
        queries[u].push_back({v, l});
    }

    
    for (int u = 1; u <= n; u++) {
        for (auto pp: queries[u]) aa[0][pp.first] = -pp.second;
        vector<LL> dist0 = dijkstra(0);
        vector<LL> dist1 = dijkstra(u);
        for (int a = 1; a <= n; a++) {
            for (int b = a+1; b <= n; b++) {
                ans[a][b] |= dist0[a] + aa[a][b] + dist1[b] <= 0;
                ans[a][b] |= dist0[b] + aa[b][a] + dist1[a] <= 0;
            }
        }
        for (auto pp: queries[u]) aa[0][pp.first] = INF;
    }

    int res = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = a+1; b <= n; b++) {
            res += ans[a][b];
        }
    }
    cout << res << "\n";
}