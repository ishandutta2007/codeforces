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

struct Edge {
    int s, t;
    int id;
};

const int MAXN = 301000;
vector<Edge> aa[MAXN];

LL asph[MAXN];
int anc[MAXN];
int sz[MAXN];
int ancestor(int v) {
    if (anc[anc[v]] != anc[v]) anc[v] = ancestor(anc[v]);
    return anc[v];
}

int join(int u, int v) {
    assert(u != v);
    assert(u == anc[u]);
    assert(v == anc[v]);
    if (sz[u] < sz[v]) swap(u, v);
    anc[v] = u;
    sz[u] += sz[v];
    if (aa[u].size() < aa[v].size()) swap(aa[u], aa[v]);
    for (const auto& e: aa[v]) aa[u].push_back(e);
    return u;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, m;
    LL x;
    LL sum = 0;
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++) cin >> asph[i], sum += asph[i];
    if (sum < (n-1)*x) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) anc[i] = i, sz[i] = 1;
    for (int i = 1; i <= m; i++) {
        Edge e;
        cin >> e.s >> e.t;
        e.id = i;
        aa[e.s].push_back(e);
        swap(e.s, e.t);
        aa[e.s].push_back(e);
    }
    
    priority_queue<pair<LL,int>> q;
    for (int v = 1; v <= n; v++) q.push({asph[v], v});
    for (int _ = 0; _ < n-1; _++) {
        auto pp = q.top();
        q.pop();
        int v = pp.second;
        if (v != anc[v] or asph[v] != pp.first) {
            _--;
            continue;
        }
        while (ancestor(aa[v].back().t) == v) aa[v].pop_back();
        cout << aa[v].back().id << "\n";
        int u = ancestor(aa[v].back().t);
        LL a = asph[u] + asph[v]-x;
        assert(a >= 0);
        int boss = join(u, v);
        asph[boss] = a;
        q.push({asph[boss], boss});
    }
}