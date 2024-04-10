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
const ll MAXN = 301000;

vi V[MAXN];
queue<int> Q;
int dst[MAXN];
int N,M,a,b;
int out[MAXN];
int p[MAXN];
int par(int x){return (p[x]==x)?x:p[x] = par(p[x]);}
vi prior;
vi S[MAXN];
vpi E;
int undes[MAXN];

bool cmp(int a, int b){
  for (int i=0;i<SZ(S[a])&&i<SZ(S[b]);++i){
    if (S[a][i]!=S[b][i])return S[a][i] < S[b][i];
  }
  return SZ(S[a]) < SZ(S[b]);
}

int main(){
  cin>>N>>M;
  for (int i=0;i<M;++i){
    cin>>a>>b;
    S[a].pb(b);S[b].pb(a);
    E.pb(a,b);
  }
  for (int i=1;i<=N;++i){
    S[i].pb(i);
    sort(ALL(S[i]));
    prior.pb(i);
    p[i]=i;
  }
  sort(ALL(prior), cmp);
  for (int i=1;i<N;++i){
    int a = prior[i-1];
    int b = prior[i];
    if (SZ(S[a])!=SZ(S[b]))continue;
    int die=0;
    for (int j=0;j<SZ(S[a]);++j){
      if(S[a][j]!=S[b][j]){die=1;break;}
    }
    if(die)continue;
    p[par(a)] = par(b);
    // cout<<a<<' '<<b<<'\n';
  }
  vi des;
  for (int i=1;i<=N;++i)des.pb(par(i));
  sort(ALL(des));des.resize(unique(ALL(des)) - des.begin());
  for (int i=0;i<SZ(des);++i){
    undes[des[i]] = i+1;
  }
  
  // for (int i=1;i<=N;++i)p[i] = undes[p[i]];
  int NN = SZ(des);
  // cout<<NN<<'\n';

  for (auto i : E){
    if (p[i.f]!=i.f || p[i.s]!=i.s)continue;
    int a = undes[p[i.f]];
    int b= undes[p[i.s]];
    // cout<<a<<' '<<b<<'\n';
    V[a].pb(b);V[b].pb(a);
  }
  for (int i=1;i<=NN;++i){
    out[i]=INF;
    sort(ALL(V[i]));
    V[i].resize(unique(ALL(V[i])) - V[i].begin());
  }

  dst[1]=1;
  Q.push(1);
  while (SZ(Q)){
    int t=Q.front();Q.pop();
    // cout<<t<<' '<<dst[t]<<'\n';
    for (auto x:V[t])if(dst[x] == 0){
      dst[x] = dst[t]+1;
      Q.push(x);
    }
  }

  out[1]=0;
  vi l2;
  for (int i=1;i<=NN;++i)if(dst[i] == 2)l2.pb(i);
  int rte = 1;
  int totedge = 0;
  // for (int i=1;i<=NN;++i)cout<<dst[i]<<' ';cout<<'\n';

  for (auto i : l2){
    // cout<<i<<' ';
    if (out[i] != INF)continue;
    int sz=0;
    if (rte == -INF){
      cout<<"NO";
      return 0;
    }
    Q.push(i);
    out[i] = rte;
    if (rte == 1)rte = -1;
    else rte = -INF;

    while (SZ(Q)){
      int t=Q.front();Q.pop();
      ++sz;
      for (auto x:V[t])if(dst[x] == 2){
        if (out[x] == INF){
          out[x]=out[t];
          Q.push(x);
        }else if (out[x]!=out[t]){
          cout<<"NO";
          return 0;
        }
      }
    }
    totedge += sz*(sz-1)/2;
  }
  for (auto i : l2){
    for (auto x:V[i])if (dst[x] == 2)--totedge;
  }
  if(totedge!=0){
    cout<<"NO";
    return 0;
  }

  for (auto i : l2)Q.push(i);
  while (SZ(Q)){
    int t=Q.front();Q.pop();

    int c = out[t];
    int nx=out[t]+1;
    if (c<0)nx = out[t] - 1;
    for (auto x:V[t])if(dst[x] == dst[t] + 1){
      if (out[x] == INF){
        out[x] = nx;
        Q.push(x);
      }else{
        cout<<"NO";
        return 0;
      }
    }
  }


  int off = *min_element(out+1,out+1+NN) - 1;

  // for (int i=1;i<=NN;++i)cout<<out[i]<<' ';cout<<'\n';
  cout<<"YES\n";
  for (int i=1;i<=N;++i)cout<<out[undes[p[i]]]-off<<' ';
  // for (int i=1;i<=N;++i)if(dst[i]==2)cout<<"Node "<<i<<" location "<<i<<'\n';
}