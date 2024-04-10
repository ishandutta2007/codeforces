#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
vector<ll> y;
ll N,P,K;
bool c(ll k){
  ll tot=0;
  if(k%K)tot+=y[(k%K-1)];
  for(ll i=k%K+K-1;i<k;i+=K){
    tot+=v[i];
  }
  return tot<=P;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T;
    cin>>T;
    while(T--){
      cin>>N>>P>>K;
      v.resize(N);y.resize(N);
      for(ll i=0;i<N;i++)cin>>v[i];
      sort(v.begin(),v.end());
      y[0]=v[0];
      for(ll i=1;i<N;i++)y[i]=y[i-1]+v[i];
      ll sx=0,dx=N+1;
      if(c(K))sx=K;
      else dx=K;
      while(sx<dx-1){
        ll m=(sx+dx)/2;
        if(c(m))sx=m;
        else dx=m;
      }
      cout<<sx<<'\n';
    }
    return 0;
}