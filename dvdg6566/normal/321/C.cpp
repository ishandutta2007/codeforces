#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
int MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define dst distance
int INF = 1e9+9;
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()

struct CentDecomp{
  vector<vi> V;
  vi par;
  vi sub;
  vi ban;
  int N,c;

  CentDecomp(int _N){
    N = _N;
    sub.resize(N+1,0);
    par.resize(N+1,0);
    ban.resize(N+1,-1);
    V.resize(N+1);
  }

  void build(int u, int p, int l){
    int n = dfs1(u,p,l); //Find the size of each subtree
    int cent = dfs2(u, p, n); // Find the Centroid
    if (p == -1)p = cent; // Parent of root is urself
    par[cent] = p;
    ban[cent] = l;
    for (auto v : V[cent]){
      if (ban[v]!=-1)continue; 
      build(v, cent,l+1);
    }
  }
  
  int dfs1(int u, int p, int l){
    sub[u] = 1;
    for (auto v : V[u]){
      if (ban[v]!=-1)continue;
      if (v == p)continue;
      sub[u] += dfs1(v,u,l);
    }
    return sub[u];
  }

  int dfs2(int u, int p, int n){
    for (auto v : V[u]){
      if (ban[v]!=-1)continue;
      if (v != p && sub[v] > n/2){
        ++c;
        return dfs2(v,u,n);
      }
    }
    return u;
  }
}*G;

int N,a,b;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N;
  G = new CentDecomp(N);
  for (int i=1;i<N;++i){
    cin>>a>>b;
    G->V[a].pb(b);
    G->V[b].pb(a);
  }
  G->build(1,-1,0);
  for (int i=1;i<=N;++i)cout<<(char)(G->ban[i]+'A')<<' ';
}