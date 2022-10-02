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

const int MAXN = 210;
vector<int> aa[MAXN];
vector<int> diff[MAXN];
vector<int> ww[MAXN];
bool visited[MAXN];
int curr_c = 0;
int cc[MAXN];
int val[MAXN];

bool works = true;

void dfs(int v) {
    cc[v] = curr_c;
    visited[v] = true;
    for (int i = 0; i < SZ(aa[v]); i++) {
        int a = aa[v][i];
        if (visited[a]) {
            if (val[a] != val[v] + diff[v][i]) {
                works = false;
            }
        } else {
            val[a] = val[v] + diff[v][i];
            dfs(a);
        }
    }
}

typedef pair<int,int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, m;
    cin >> n >> m;
    vector<pii> un_edge;
    for (int i = 0; i < m; i++) {
        int u, v, b;
        cin >> u >> v >> b;
        if (b == 0) un_edge.push_back({u, v});
        else {
            aa[u].push_back(v);
            aa[v].push_back(u);
            diff[u].push_back(1);
            diff[v].push_back(-1);
        }
    }
    for (int v = 1; v <= n; v++) {
        if (visited[v]) continue;
        dfs(v);
        curr_c++;
    }

    if (!works) {
        cout << "NO\n";
        return 0;
    }

    int C = curr_c;
    vector<int> min_pos(C, 1e9);
    vector<int> max_pos(C, -1);
    vector<int> sz_c(C+1, 0);
    for (int v = 1; v <= n; v++) {
        min_pos[cc[v]] = min(min_pos[cc[v]], val[v]);
        max_pos[cc[v]] = max(max_pos[cc[v]], val[v]);
    }
    // dbg(C, min_pos, max_pos);
    for (int v = 1; v <= n; v++) val[v] -= min_pos[cc[v]];
    // dbg_arr(val, n+1);
    for (int i = 1; i <= C; i++) sz_c[i] = sz_c[i-1] + max_pos[i-1]-min_pos[i-1]+1;
    vector<int> id(n+1);
    for (int v = 1; v <= n; v++) id[v] = sz_c[cc[v]] + val[v];
    for (int i = 0; i <= n; i++) aa[i].clear();
    for (auto e: un_edge) {
        int u = e.first, v = e.second;
        if (cc[u] == cc[v]) {
            if (abs(val[u] - val[v]) != 1) {
                cout << "NO\n";
                return 0;
            }
        } else {
            u = id[u];
            v = id[v];
            aa[u].push_back(v);
            aa[v].push_back(u);
            ww[u].push_back(1);
            ww[v].push_back(1);
        }
    }
    for (int c = 0; c < C; c++) {
        for (int i = sz_c[c]; i < sz_c[c+1]-1; i++) {
            aa[i].push_back(i+1);
            aa[i+1].push_back(i);
            ww[i].push_back(1);
            ww[i+1].push_back(-1);
        }
    }

    int L = sz_c[C];
    int ans = -1;
    vector<int> best_dist;
    for (int source = 0; source < L; source++) {
        vector<int> dist(L, 1e9);
        dist[source] = 0;
        for (int _ = 0; _ < L; _++) {
            for (int v = 0; v < L; v++) for (int i = 0; i < SZ(aa[v]); i++) {
                // dbg(v, i, aa[v].size(), ww[v].size(), aa[v][i], ww[v][i]);
                dist[aa[v][i]] = min(dist[aa[v][i]], dist[v] + ww[v][i]);
            }
        }
        bool neg_cycle = false;
        for (int v = 0; v < L; v++) for (int i = 0; i < SZ(aa[v]); i++) {
            if (dist[aa[v][i]] > dist[v] + ww[v][i]) neg_cycle = true;
        }
        if (neg_cycle) continue;

        bool broken = false;
        for (int c = 0; c < C; c++) {
            for (int i = sz_c[c]; i < sz_c[c+1]-1; i++) {
                if (dist[i] + 1 != dist[i+1]) broken = true;
            }
        }
        for (int v = 0; v < L; v++) for (int a: aa[v]) { // bipartite
            if (abs(dist[v]-dist[a]) != 1) broken = true;
        }
        
        if (broken) continue;

        int mm = 0;
        for (int i = 0; i < L; i++) mm = max(mm, dist[i]);
        if (mm > ans) {
            ans = mm;
            best_dist = dist;
        }
        ans = max(ans, mm);
    }

    if (ans == -1) cout << "NO\n";
    else {
        cout << "YES\n";
        cout << ans << "\n";
        for (int v = 1; v <= n; v++) cout << best_dist[id[v]] << " ";
        cout << "\n";
    }
    
}