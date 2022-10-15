#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MOD = 998244353;
const ll INF = 1e9;
const ll MAXN = 200100;
typedef pair<pi,int> ppi;
#define v(x) vector<x>

vi V[MAXN];
int N,a,b;
pi depth[MAXN];
pi frmtop[MAXN];
int par[MAXN];
vi ew;

void dfs(int x, int p){
  ew.pb(x);
  par[x]=p;
  depth[x]=mp(0,x);
  for(auto v:V[x])if(v!=p){
    dfs(v,x);
    if(depth[v].f+1>depth[x].f){
      depth[x]=depth[v];
      ++depth[x].f;
    }
  }
}

void dfs2(int x, int p){
  v(ppi) cur;
  cur.pb(frmtop[x],x);
  for (auto v:V[x])if(v!=p)cur.pb(mp(depth[v].f+1,depth[v].s),v);
  sort(ALL(cur));reverse(ALL(cur));
  for (auto v:V[x])if(v!=p){
    // cout<<"Doing "<<v<<'\n';
    if(cur[0].s==v){
      frmtop[v]=cur[1].f;
    }else{
      frmtop[v]=cur[0].f;
    }
    ++frmtop[v].f;
  }
  for (auto v:V[x])if(v!=p)dfs2(v,x);
}

int main(){
  cin>>N;
  for(int i=1;i<N;++i){
    cin>>a>>b;
    V[a].pb(b);V[b].pb(a);
  }
  int rt=1;for (int i=2;i<=N;++i)if(SZ(V[i])<SZ(V[rt])){rt=i;}
  dfs(rt,-1);
  frmtop[rt]=mp(0,rt);
  dfs2(rt,-1);

  ppi out;
  int ans=-1;
  for (int i=1;i<=N;++i){
    if (SZ(V[i])<3)continue;
    vpi cur;
    for (auto t:V[i])if(t!=par[i]){
      cur.pb(mp(depth[t].f+1,depth[t].s));
    }
    cur.pb(frmtop[i]);
    // for(auto x:cur)cout<<x.f<<' '<<x.s<<'\n';
    // cout<<'\n';
    sort(ALL(cur));reverse(ALL(cur));
    int curans=cur[0].f+cur[1].f+cur[2].f;
    if (curans>ans){
      out=mp(mp(cur[0].s,cur[1].s), cur[2].s);
      ans=curans;
    }
  }
  if(ans==-1){
    cout<<N-1<<'\n';
    cout<<ew[0]<<' '<<ew[1]<<' '<<ew.back();
    return 0;
  }
  cout<<ans<<'\n';
  cout<<out.f.f<<' '<<out.f.s<<' '<<out.s;
}