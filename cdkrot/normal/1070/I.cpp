#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()



typedef long long ll;

struct edge_t {
    int to;
    int flow;
    int cap;
    int next;
};

int push(int v, int tg, vector<int>& head, vector<edge_t>& edges, vector<char>& used) {
    if (v == tg)
        return 1;
    
    used[v] = 1;

    for (int ed = head[v]; ed != -1; ed = edges[ed].next) {
        if (edges[ed].flow < edges[ed].cap and not used[edges[ed].to] and push(edges[ed].to, tg, head, edges, used)) {
            edges[ed].flow += 1;
            edges[ed ^ 1].flow -= 1;

            return 1;
        }
    }

    return 0;
}

int kukarek(vector<int>& head, vector<edge_t>& edges, vector<char>& used, vector<vector<int>>& list, int v, int tg) {
    int OFF_VERT = 2;
    int OFF_EDG  = 2 + SZ(list);

    if (v == tg)
        return 1;

    for (int ed = head[v]; ed != -1; ed = edges[ed].next)
        if (edges[ed].flow > 0 and not used[edges[ed].to] and kukarek(head, edges, used, list, edges[ed].to, tg)) {
            edges[ed].flow -= 1;
            edges[ed ^ 1].flow += 1;

            int to = edges[ed].to;
            if (OFF_VERT <= v and v < OFF_EDG and OFF_EDG <= to) {
                list[v - OFF_VERT].push_back(to - OFF_EDG);
            }
            
            return 1;
        }

    return 0;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int S = 0;
    int T = 1;
    int OFF_VERT = 2;
    int OFF_EDG  = 2 + n;

    vector<int> head(2 + n + m, -1);

    vector<edge_t> edges;

    vector<int> deg(n);
        
    auto add_edge = [&](int from, int to, int cap) {
        edges.push_back(edge_t {to, 0, cap, head[from]});
        head[from] = SZ(edges) - 1;

        edges.push_back(edge_t {from, 0, 0, head[to]});
        head[to] = SZ(edges) - 1;
    };

    for (int i = 0; i != m; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;

        add_edge(OFF_VERT + v, OFF_EDG + i, 1);
        add_edge(OFF_VERT + u, OFF_EDG + i, 1);

        deg[v] += 1;
        deg[u] += 1;
    }

    for (int i = 0; i != m; ++i)
        add_edge(OFF_EDG + i, T, 1);

    int need_flow = 0;
    for (int i = 0; i != n; ++i) {
        // deg[i] - 2 * t = t <= k
        // deg[i] - t <= k
        // t >= deg[i] - k

        add_edge(S, OFF_VERT + i, 2 * max(0, deg[i] - k));
        need_flow += 2 * max(0, deg[i] - k);
    }

    int flow = 0;
    while (true) {
        vector<char> used(SZ(head), false);
        if (push(S, T, head, edges, used))
            flow += 1;
        else
            break;
    }

    if (flow != need_flow) {
        for (int i = 0; i != m; ++i)
            cout << "0 ";
        cout << "\n";
    } else {
        vector<int> ans(m);
        std::iota(ALL(ans), 1);

        vector<vector<int>> list(n);
        
        for (int it = 0; it != flow; ++it) {
            vector<char> used(SZ(head), false);
            kukarek(head, edges, used, list, 0, T);
        }

        for (int v = 0; v != n; ++v) {
            for (int i = 0; i < SZ(list[v]); i += 2)
                ans[list[v][i + 1]] = ans[list[v][i]];
        }

        for (auto elem: ans)
            cout << elem << " ";
        cout << "\n";
    }
}

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for (int t = input<int>(); t != 0; --t) {
        solve();
    }
    
    return 0;
}