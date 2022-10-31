#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define fst first
#define snd second
#define mp make_pair
#define pb push_back

#define rep(i, n) for(int i = 0; i < n; ++i)
#define repe(i, n) for(int i = 0; i <= n; ++i)

#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d%d", &x, &y)
#define riii(x,y,z) scanf("%d%d%d", &x, &y, &z)
#define ria(a, n) rep(_, n) scanf("%d", &a[_])

#define pi(x) printf("%d\n", x)
#define pia(a, n) rep(_, n) printf("%d%c", a[_], _==n-1?'\n': ' ')

#define Ttimes int T; scanf("%d", &T); while(T--)


const int maxn = 100 + 10;
const int INF = 1000000000;
struct Edge { int from, to, cap, flow; };
bool operator < (const Edge& a, const Edge& b) {
  return a.from < b.from || (a.from == b.from && a.to < b.to);
}
struct Dinic {
  int n, m, s, t;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool vis[maxn];
  int d[maxn];
  int cur[maxn];
  void ClearAll(int n) {
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }
  void ClearFlow() {
    for(int i = 0; i < edges.size(); i++) edges[i].flow = 0;    
  }
  void AddEdge(int from, int to, int cap) {
    // printf("add %d - %d: %d\n", from, to, cap);
    edges.push_back((Edge){from, to, cap, 0});
    edges.push_back((Edge){to, from, 0, 0});
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }
  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<int> Q;
    Q.push(s);
    vis[s] = 1;
    d[s] = 0;
    while(!Q.empty()) {
      int x = Q.front(); Q.pop();
      for(int i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if(!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }
  int DFS(int x, int a) {
    if(x == t || a == 0) return a;
    int flow = 0, f;
    for(int& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap-e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i]^1].flow -= f;
        flow += f;
        a -= f;
        if(a == 0) break;
      }
    }
    return flow;
  }
  int Maxflow(int s, int t) {
    this->s = s; this->t = t;
    int flow = 0;
    while(BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }
  vector<int> Mincut() { // call this after maxflow
    vector<int> ans;
    for(int i = 0; i < edges.size(); i++) {
      Edge& e = edges[i];
      if(vis[e.from] && !vis[e.to] && e.cap > 0) ans.push_back(i);
    }
    return ans;
  }
  void Reduce() {
    for(int i = 0; i < edges.size(); i++) edges[i].cap -= edges[i].flow;
  }
} g;


int n, m, a[110];
int x[110], y[110], d[110] = {};
bool vis[110] = {};

long long ans = 0;
int gds[110][110];

void jizz(int t) {
    // printf("jizz %d\n", t);
    g.ClearAll(n + 2);
    rep(i, m) {
        int jiz = 0, tmp = gds[x[i]][y[i]];
        while(tmp % t == 0) {
            tmp /= t;
            jiz++;
        }
        if(jiz) {
            // printf("add %d - %d: %d\n", x[i], y[i], jiz);
            g.AddEdge(x[i], y[i], jiz);
        }
    }
    rep(i, n) {
        int jiz = 0, tmp = a[i];
        while(tmp % t == 0) {
            tmp /= t;
            jiz++;
        }
        if(jiz) {
            if(i % 2 == 0) g.AddEdge(n, i, jiz);
            else g.AddEdge(i, n + 1, jiz);
        }
    }
    ans += g.Maxflow(n, n + 1);
}

set<int> pp;
void fuck(int x) {
    for(int i = 2; 1LL * i * i <= x; ++i) {
        if(x % i == 0) {
            while(x % i == 0) x /= i;
            pp.insert(i);
        }
    }
    if(x > 1) {
        pp.insert(x);
    }
}

int main() {
    rii(n, m);
    ria(a, n);
    rep(i, m) {
        rii(x[i], y[i]);
        x[i]--, y[i]--;
        if(x[i] % 2 == 1) swap(x[i], y[i]);
        gds[x[i]][y[i]] = __gcd(a[x[i]], a[y[i]]);
        fuck(gds[x[i]][y[i]]);
    }
    for(auto v: pp)
        jizz(v);
    cout << ans << endl;
    return 0;
}