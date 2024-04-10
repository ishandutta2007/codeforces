#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SZ(a) a.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;
struct Dinic{
  static const int MXN = 10000;
  struct Edge{ int v,f,re; };
  int n,s,t,level[MXN];
  vector<Edge> E[MXN];
  void init(int _n, int _s, int _t){
    n = _n; s = _s; t = _t;
    for (int i=0; i<n; i++) E[i].clear();
  }
  void add_edge(int u, int v, int f){
    E[u].PB({v,f,SZ(E[v])});
    E[v].PB({u,0,SZ(E[u])-1});
  }
  bool BFS(){
    for (int i=0; i<n; i++) level[i] = -1;
    queue<int> que;
    que.push(s);
    level[s] = 0;
    while (!que.empty()){
      int u = que.front(); que.pop();
      for (auto it : E[u]){
        if (it.f > 0 && level[it.v] == -1){
          level[it.v] = level[u]+1;
          que.push(it.v);
        }
      }
    }
    return level[t] != -1;
  }
  int DFS(int u, int nf){
    if (u == t) return nf;
    int res = 0;
    for (auto &it : E[u]){
      if (it.f > 0 && level[it.v] == level[u]+1){
        int tf = DFS(it.v, min(nf,it.f));
        res += tf; nf -= tf; it.f -= tf;
        E[it.v][it.re].f += tf;
        if (nf == 0) return res;
      }
    }
    if (!res) level[u] = -1;
    return res;
  }
  int flow(int res=0){
    while ( BFS() )
      res += DFS(s,2147483647);
    return res;
  }
}flow;

vi G[305];

int a[305], np[20005];
bool vis[305];
vi ans[305];
int ct = 0, n;

void dfs(int u) {
	if(u > n) return;
	vis[u] = 1;
	ans[ct].PB(u);
	for(int v:G[u])
		if(vis[v] == 0)
			dfs(v);
}

int main()
{
	IO_OP;
	
	np[0] = np[1] = 1;
	for(int i=2;i*i<20005;i++) {
		if(np[i]) continue;
		for(int j=i*i;j<20005;j+=i)
			np[j] = 1;
	}
	cin >> n;
	vi odd, even;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i] % 2) odd.PB(i);
		else even.PB(i);
	}
	
	int s = 0, t = n+1;
	flow.init(n+2, s, t);
	for(int u:even) {
		flow.add_edge(s, u, 2);
		for(int v:odd) {
			if(np[a[u]+a[v]] == 0) {
				flow.add_edge(u, v, 1);
			}
		}
	}
	for(int v:odd)
		flow.add_edge(v, t, 2);
	
	if(flow.flow() == even.size()*2 && odd.size() == even.size()) {
		for(int u:even) {
			for(int i=0;i<flow.E[u].size();i++) {
				if(flow.E[u][i].f == 0) {
					G[u].PB(flow.E[u][i].v);
					G[flow.E[u][i].v].PB(u);
				}
			}
		}
		for(int i=1;i<=n;i++) {
			if(vis[i] == 0) {
				dfs(i);
				ct++;
			}
		}
		cout << ct << endl;
		for(int i=0;i<ct;i++) {
			cout << ans[i].size() << " ";
			for(int u:ans[i])
				cout << u << " ";/*
			for (int j = 0; j < ans[i].size(); j++) {
				cerr << ans[i][j] <<' ' <<ans[i][(j+1) % ans[i].size()]<<endl;
				cerr << a[ans[i][j]] << ' ' << a[ans[i][(j+1) % ans[i].size()]]<<endl;
				cerr<<"============\n";
				assert(np[a[ans[i][j]] + a[ans[i][(j+1) % ans[i].size()]]] == 0);
			}*/
			cout << endl;
		}
	} else {
		cout << "Impossible" << endl;
	}
}