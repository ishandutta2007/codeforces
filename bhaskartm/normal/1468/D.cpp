#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define endl '\n'
#define all(x) x.begin(),x.end()
#define sz(x) (ll)x.size()
#define MOD 1000000007
#define F first
#define S second
#ifdef LOCAL
    #include "trace.h"
#else
    #define trace(args...)
#endif
 
ll div_floor(const ll &a,const ll &b) { return a / b - (((a ^ b) < 0) and a % b);}
ll div_ceil(const ll &a,const ll &b) { return a / b + (((a ^ b) >= 0) and a % b);}

void solve(){
  ll n, m, a, b; cin>>n>>m>>a>>b;
  vector<ll> s(m); for(auto &e: s) cin>>e;

  ll time = 0;
  if(a<b)
    time = b - 1;
  else
    time = n - b;
  
  vector<ll> t = s;
  for(auto &e: t) e = time - e;
  sort(all(t));

  ll ans = 0;

  for(ll i = min(m, abs(a-b)-1); i>=1; i--){
    ll cnt = m - (lower_bound(all(t), i) - t.begin());
    if(cnt>ans) ans++; 
  }
  cout<<ans<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifdef LOCAL
    freopen("inp.txt", "r", stdin);
      freopen("out.txt", "w", stdout);
      freopen("err.txt", "w", stderr);
  #endif
  ll t=1;
  cin>>t;
  while(t--)
    solve();
}