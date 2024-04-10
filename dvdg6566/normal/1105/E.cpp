#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
ll INF = 100000000000000000;
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

map<string,int> M;
map<ll,ll> Ma, Mb;
ll d[41];
ll dp[(1<<20) + 10];
si V;
ll N,K,a,b,ans;
string st;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("in.txt","r",stdin);
  cin>>N>>K;
  b = 1;
  for (int i=0;i<K;++i)d[i] = (1LL<<i);
  // for (int i=0;i<K;++i)cout<<d[i]<<' ';cout<<'\n';
  for (int i=0;i<N;++i){
    cin>>a;
    if (a == 1){
      for (auto i : V){
        for (auto j : V){
          if (i == j)continue;
          d[i-1] = d[i-1] | (1LL<<(j-1));
        }
      }
      V.clear();
    }
    else{
      cin>>st;
      if (M[st] == 0){
        M[st] = b++;
      }
      V.insert(M[st]);
    }
  }
  for (auto i : V){
    for (auto j : V){
      if (i == j)continue;
      d[i-1] = d[i-1] | (1LL<<(j-1));
    }
  }
  // for (int i=0;i<K;++i)cout<<d[i]<<' ';cout<<'\n';
  int hp = (K+1)/2;
  Ma[0] = 0;
  for (int i=0; i<hp; ++i){
    for (auto it : Ma){
      if (it.f & d[i])continue;
      ll x = it.f + (1LL<<i), w = it.s + 1;
      Mb[x] = max(Mb[x], w);
    }
    for (auto it : Mb){
      Ma[it.f] = max(Ma[it.f], it.s);
    }
    Mb.clear();
  }
  // for (auto i : Ma)cout<<i.f<<' '<<i.s<<'\n';cout<<'\n';
  for (int i=0;i<(1LL<<hp); ++i){
    dp[i] = Ma[i];
    for (int j=0;j<hp;++j){
      if ((1LL<<j) & i){
        dp[i] = max(dp[i], dp[i - (1LL<<j)]);
      }
    }
  }
  // for (int i=0;i<(1<<hp);++i)cout<<dp[i]<<' ';cout<<'\n';
  Ma.clear();
  Ma[0] = 0;
  for (int i=hp;i<K;++i){
    for (auto it : Ma){
      if (it.f & (1LL<<i))continue;
      ll x = it.f | d[i], w = it.s + 1;
      Mb[x] = max(Mb[x], w);
    }
    for (auto it : Mb){
      Ma[it.f] = max(Ma[it.f], it.s);
    }
    Mb.clear();
  }
  ll tt = (1LL<<hp) - 1;
  for (auto i : Ma){
    ll cur = 0;
    for (int it = 0; it < hp; ++it){
      if ((1<<it) & i.f)continue;
      cur += (1<<it);
    }
    ans = max(ans, i.s+dp[cur]);
  }
  // return 0;
    cout<<ans;
    
}