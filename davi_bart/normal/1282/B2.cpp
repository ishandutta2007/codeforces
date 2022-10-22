#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> v;
vector<ll> y;
ll N,P,K;
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
      int ma=0;
      for(int i=0;i<K;i++){
        int tot=0;
        if(i!=0)tot=y[i-1];
        if(tot>P)break;
        ma=max(ma,i);
        for(int j=i+K-1;j<N;j+=K){
          tot+=v[j];
          if(tot>P)break;
          ma=max(ma,j+1);
        }
      }
      cout<<ma<<'\n';
    }
    return 0;
}