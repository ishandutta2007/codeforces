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

vi V[4];
ll N,M,a,b;
vi T[4];
ll optot[MAXN];


int main(){
  cin>>N>>M;
  for (ll i=0;i<N;++i){
    cin>>a>>b;
    V[a].pb(b);
  }
  for (ll i=1;i<=3;++i){
    sort(ALL(V[i]));
    // reverse(ALL(V[i]));
  }
  // first we do even stuff
  vi tmp; vi grdy;
  for (auto i : V[1])tmp.pb(i);
  while (SZ(tmp) > 1){
    ll a=tmp.back();tmp.pop_back();
    a += tmp.back();tmp.pop_back();
    grdy.pb(a);
  } 
  for (auto t:V[2])grdy.pb(t);
  sort(ALL(grdy));
  for (ll i=2;i<=M;i+=2){
    if (SZ(grdy) == 0){optot[i] = optot[i-2];continue;}
    optot[i] = optot[i-2] + grdy.back();
    grdy.pop_back();
  }

  // for (ll i=1;i<=M;++i)cout<<optot[i]<<' ';cout<<'\n';

  tmp.clear();grdy.clear();
  if (SZ(V[1])){
    for (auto i : V[1])tmp.pb(i);
    optot[1] = tmp.back();tmp.pop_back();  

    while (SZ(tmp) > 1){
      ll a=tmp.back();tmp.pop_back();
      a += tmp.back();tmp.pop_back();
      grdy.pb(a);
    }
    for (auto t:V[2])grdy.pb(t);
    sort(ALL(grdy));
    for (ll i=3;i<=M;i+=2){
      if (SZ(grdy) == 0){optot[i] = optot[i-2];continue;}
      optot[i] = optot[i-2] + grdy.back();
      grdy.pop_back();
    }
  }

  for (ll i=1;i<=M;++i)optot[i] = max(optot[i], optot[i-1]);

  ll ans = *max_element(optot,optot+M+1);
  ll pre = 0;
  ll leftovers = M;
  while(SZ(V[3]) && leftovers >= 3){
    leftovers -= 3;
    pre += V[3].back();V[3].pop_back();
    ans = max(ans, pre+optot[leftovers]);
  }
  cout<<ans;
}