#include <bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define dbg(a) cerr << #a << " = " << a << endl; 
#define forn(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

int n, m;
char a[222][222];


struct Dinic{
    struct edge{
        int to, flow, cap;
    };

    const static int N = 202 * 202; //count of vertices

    vector<edge> e;
    vector<int> g[N + 7];
    int dp[N + 7];
    int ptr[N + 7];

    void clear(){
        for (int i = 0; i < N + 7; i++) g[i].clear();
        e.clear();
    }

    void addEdge(int a, int b, int cap = 1){
        g[a].pb(e.size());
        e.pb({b, 0, cap});
        g[b].pb(e.size());
        e.pb({a, 0, 0});
    }

    int minFlow, start, finish;

    bool bfs(){
        for (int i = 0; i < N; i++) dp[i] = -1;
        dp[start] = 0;
        vector<int> st;
        int uk = 0;
        st.pb(start);
        while(uk < st.size()){
            int v = st[uk++];
            for (int to : g[v]){
                auto ed = e[to];
                if (ed.cap - ed.flow >= minFlow && dp[ed.to] == -1){
                    dp[ed.to] = dp[v] + 1;
                    st.pb(ed.to);
                }
            }
        }
        return dp[finish] != -1;
    }

    int dfs(int v, int flow){
        if (v == finish) return flow;
        for (; ptr[v] < g[v].size(); ptr[v]++){
            int to = g[v][ptr[v]];
            edge ed = e[to];
            if (ed.cap - ed.flow >= minFlow && dp[ed.to] == dp[v] + 1){
                int add = dfs(ed.to, min(flow, ed.cap - ed.flow));
                if (add){
                    e[to].flow += add;
                    e[to ^ 1].flow -= add;
                    return add;
                }
            }
        }
        return 0;
    }

    int dinic(int start, int finish){
        Dinic::start = start;
        Dinic::finish = finish;
        int flow = 0;
        for (minFlow = 1; minFlow; minFlow >>= 1){
            while(bfs()){
                for (int i = 0; i < N; i++) ptr[i] = 0;
                while(int now = dfs(start, (int)2e9 + 7)) flow += now;
            }
        }
        return flow;
    }
} dinic;


int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];

  int s = n * m;
  int t = n * m + 1;

  auto get_node = [](int x, int y) { return x * m + y; };

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) if (a[i][j] == '#') {
      if (i > 0 && a[i - 1][j] == '#') dinic.addEdge(get_node(i, j), get_node(i - 1, j));
      if (j + 1 < m && a[i][j + 1] == '#') dinic.addEdge(get_node(i, j), get_node(i, j + 1));
      if (j == 0 || a[i][j - 1] == '.') dinic.addEdge(s, get_node(i, j));
      if (i == 0 || a[i - 1][j] == '.') dinic.addEdge(get_node(i, j), t);
    }
  }

  cout << dinic.dinic(s ,t);

}