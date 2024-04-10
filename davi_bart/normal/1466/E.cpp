#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N;
const int mod=1e9+7;
void solve(){
  cin>>N;
  vector<int> v(N);
  for(int &i:v)cin>>i;
  int sum=0;
  vector<int> p(70,0);
  vector<int> agg;
  for(int i:v){
    sum+=i;
    sum%=mod;
    for(int j=0;j<60;j++){
      if(i&((int)1<<j))p[j]++;
    }
  }
  for(int i:v){
    int o=0;
    for(int j=0;j<60;j++){
      if((i&((int)1<<j))==0)continue;
      o+=(N-p[j])*(((int)1<<j)%mod)%mod;
      o%=mod;
    }
    agg.pb(o);
  }

  int ans=0;
  for(int a=0;a<N;a++){
    int i=v[a];
    for(int j=0;j<60;j++){
      if((i&((int)1<<j))==0)continue;
      ans+=((int)1<<j)%mod*p[j]%mod*(sum+agg[a])%mod;
      ans%=mod;
    }
  }
  cout<<ans<<'\n';

}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}