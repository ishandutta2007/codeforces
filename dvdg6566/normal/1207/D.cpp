#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
ll MOD = 998244353;

vpi V;
ll N,a,b;
ll dem[300100];
ll L,R;
ll fact[300100];

int main(){
  fact[0] = 1;
  for (int i=1;i<=300050;++i)fact[i] = (i*fact[i-1])%MOD;
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>a>>b;
    V.pb(a,b);
  }
  L=R=1;
  for (int i=0;i<N;++i){
    dem[V[i].f] += 1;
  }
  for (int i=0;i<=N;++i)if(dem[i]){
    L = L*fact[dem[i]];
    L = L%MOD;
  }
  memset(dem,0,sizeof(dem));
  for (int i=0;i<N;++i){
    dem[V[i].s] += 1;
  }
  for (int i=0;i<=N;++i)if(dem[i]){
    R = R*fact[dem[i]];
    R = R%MOD;
  }
  // cout<<L<<' '<<R<<'\n';
  ll T = fact[N];
  T = MOD + MOD + T - L - R;
  T %= MOD;
  sort(ALL(V));
  bool ok = 1;
  for (int i=1;i<N;++i){
    if (V[i].s < V[i-1].s){
      ok = 0;
    }
  }
  if (ok == 0){
    cout<<T;
    return 0;
  }
  vi VV[300100];
  for (auto i : V){
    VV[i.f].pb(i.s);
  }
  ll stuf = 1;
  memset(dem,0,sizeof(dem));
  for (int i=0;i<=N;++i){
   for (auto x : VV[i])dem[x] ++;
   for (auto x : VV[i])if(dem[x]){
     stuf*= fact[dem[x]];
     stuf %= MOD;
     dem[x] = 0;
   }
  }
  cout<<(T+stuf)%MOD;
}