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

const int MAXN = 100100;
const int MAXL = 18;

int pp[MAXN];

int anc(int x) {
    if (pp[x] != x) pp[x] = anc(pp[x]);
    return pp[x];
}

void join(int a, int b, int w) {
    a = anc(a), b = anc(b);
    pp[a] = b;
}

struct Edge {
    int a, b, w;
};

vector<int> aa[MAXN];
vector<int> ids[MAXN];

int idp[MAXN];
int fast_pp[MAXN][MAXL];
int fast_cost[MAXN][MAXL];
int dep[MAXN];
multiset<int> ss[MAXN];
void dfs(int v, int p) {
    dep[v] = dep[p] + 1;
    fast_pp[v][0] = p;
    for (int i = 0; i < SZ(aa[v]); i++) {
        int a = aa[v][i];
        if (a == p) idp[v] = ids[v][i];
        else dfs(a, v);
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int l = MAXL-1; l >= 0; l--) if (dep[v]-(1<<l) >= dep[u]) v = fast_pp[v][l];
    if (u == v) return u;
    for (int l = MAXL-1; l >= 0; l--) if (fast_pp[u][l] != fast_pp[v][l]) u = fast_pp[u][l], v = fast_pp[v][l];
    return fast_pp[u][0];
}

multiset<int>* solve(int v, vector<int>& ans) {
    multiset<int>* curr = new multiset<int>();
    for (int a : aa[v]) {
        if (a == fast_pp[v][0]) continue;
        multiset<int>* son = solve(a, ans);
        if (son->size() > curr->size()) swap(son, curr);
        for (int x : *son) curr->insert(x);
    }
    for (int x : ss[v]) {
        if (x < 0) curr->insert(-x);
        else curr->erase(curr->find(x-1));
    }
    if (v == 1) return curr;
    if (curr->empty()) ans[idp[v]] = 1e9;
    else ans[idp[v]] = *(curr->begin());
    return curr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) pp[i] = i;
    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].a >> edges[i].b >> edges[i].w;
    }
    vector<int> ans(M, -1);
    vector<int> ord = SortIndex(M, [&](int i, int j) { return edges[i].w < edges[j].w; });
    for (int i = 0; i < M; i++) {
        Edge e = edges[ord[i]];
        if (anc(e.a) != anc(e.b)) {
            ans[ord[i]] = 0;
            join(e.a, e.b, e.w);
            aa[e.a].push_back(e.b);
            aa[e.b].push_back(e.a);
            ids[e.a].push_back(ord[i]);
            ids[e.b].push_back(ord[i]);
        }
    }
    // for (int i = 0; i < M; i++) {
        // if (ans[i] != -1) cout << ans[i] << "\n";
    // }
    // return 0;
    // dbg(ans);
    // dbg(ord);
    dfs(1, 0);
    for (int i = 1; i <= N; i++) {
        fast_cost[i][0] = edges[idp[i]].w;
    }
    for (int l = 1; l < MAXL; l++) {
        for (int i = 1; i <= N; i++) {
            fast_pp[i][l] = fast_pp[fast_pp[i][l-1]][l-1];
            fast_cost[i][l] = max(fast_cost[i][l-1], fast_cost[fast_pp[i][l-1]][l-1]);
        }
    }

    for (int i = 0; i < M; i++) {
        if (ans[i] == -1) {
            Edge e = edges[i];
            ss[e.a].insert(-e.w);
            ss[e.b].insert(-e.w);
            int l = lca(e.a, e.b);
            ss[l].insert(e.w+1);
            ss[l].insert(e.w+1);

            int v = e.a;
            // dbg(v, l, ans[i]);
            for (int z = MAXL-1; z >= 0; z--) if (dep[v] - (1<<z) >= dep[l]) {
                ans[i] = max(ans[i], fast_cost[v][z]);
                v = fast_pp[v][z];
            }
            // dbg(v, l, ans[i]);
            v = e.b;
            for (int z = MAXL-1; z >= 0; z--) if (dep[v] - (1<<z) >= dep[l]) {
                ans[i] = max(ans[i], fast_cost[v][z]);
                v = fast_pp[v][z];
            }
            cout << ans[i] << "\n";
        }
    }
    return 0;
    // dbg(ans);
    solve(1, ans);
    // dbg_arr(idp, 4);
    for (int i = 0; i < M; i++) cout << ans[i] << "\n";
}