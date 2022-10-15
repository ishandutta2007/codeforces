#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e15;
ll MOD = 1e18+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

vi ppl [100100];

struct CentDecomp{
  vector<vi> V;
  vi par, sub, ban;
  vi dst[100100][18];
  int N,c;

  CentDecomp(int _N){
    N = _N;
    sub.resize(N+1, 0);
    par.resize(N+1, 0);
    ban.resize(N+1, -1);
    V.resize(N+1);
  }

  void build (int u, int p, int l){
    // cout << "Build " << u << ' ' << p << ' ' << l << endl;
    // if (l){
      // cout<<u<<' '<<SZ(dst[u][l-1])<<'\n';
      // for (auto i : ppl[p]){
        // dst[p][l-1].pb(i);
      // }
    // } 
    int n = dfs1(u,p,l);
    int cent = dfs2(u,p,n);
    if (p == -1)p = cent;
    par[cent] = p;
    ban[cent] = l;
    // cout<<cent<<'\n';
    for (auto i : ppl[cent])dst[cent][l].pb(i);
    for (auto v : V[cent]){
      if (ban[v] != -1)continue;
      build(v,cent,l+1);
    }
  }
  
  int dfs1(int u, int p, int l){
    if (l){
      // cout << u << ' ' << p << ' ' << l <<'\n';
      for (auto i : dst[p][l-1]){
       dst[u][l-1].pb(i);
      } 
      for (auto i : ppl[u]){
        dst[u][l-1].pb(i);
      }
      sort(ALL(dst[u][l-1]));
      while (SZ(dst[u][l-1]) > 10)dst[u][l-1].pop_back();
    }

    sub[u] = 1;
    for (auto v : V[u]){
      if (ban[v] != -1)continue;
      if (v == p)continue;
      sub[u] += dfs1(v, u, l);
    }
    return sub[u];
  }

  int dfs2(int u, int p, int n){
    for (auto v : V[u]){
      if (ban[v] != -1)continue;
      if (v!=p && sub[v] > n/2){
        ++c;
        return dfs2(v, u, n);
      }
    }
    return u;
  }
}*G;

void query(int a, int b, int c){
  if (G->ban[a] < G->ban[b])swap(a, b);
  int ta = a, tb = b;
  while (G-> ban[ta] > G->ban[tb]){
    ta = G->par[ta];
  }
  while (ta != tb){
    ta = G->par[ta];
    tb = G->par[tb];
  }
  int l = G->ban[ta];
  // cout<<"LCA between " << a << ' ' << b << " is " << ta << " level " << l <<'\n';
  vi V;
  V.clear();
  for (auto it : G->dst[a][l])V.pb(it);
  for (auto it : G->dst[b][l])V.pb(it);
  sort(ALL(V));
  V.resize(unique(ALL(V)) - V.begin());
  cout<<min(c, SZ(V))<<' ';
  for (int i=0;i<c && i<SZ(V); ++i)cout<<V[i]<<' ';cout<<'\n';
  return;
}

int N,M,Q,a,b,c;


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt","r",stdin);
  cin>>N>>M>>Q;
  G = new CentDecomp(N);
  for (int i = 1; i < N; ++i){
    cin >> a >> b;
    G->V[a].pb(b);
    G->V[b].pb(a);
  }
  for (int i=1;i<=M;++i){
    cin>>a;
    ppl[a].pb(i);
    // cout<<a << ' ' << i << '\n';
  }
  for (int i=1;i<=N;++i){
    sort(ALL(ppl[i]));
    while (SZ(ppl[i]) > 10)ppl[i].pop_back();
  }
  G -> build(1, -1, 0);
  // for (int i=1;i<=N;++i)cerr<<G->ban[i]<<' ';cout<<'\n';
  // return 0;
  for (int i=0;i<Q;++i){
    cin>>a>>b>>c;
    query(a,b,c);
  }
  return 0;
  for (int i=1; i <= N; ++i){
    cout<<"For node " << i << '\n';
    for (int it = 0; it < 3; ++it){
      for (auto itt : G->dst[i][it])cout<<itt<<' ';cout<<'\n';
    }
  }
  // for (int i=1;i<=N;++i)cout<<G->par[i]<<' ';
}