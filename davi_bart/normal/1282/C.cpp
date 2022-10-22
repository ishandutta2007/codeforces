#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll rim(ll rima,ll rimb,ll ta,ll tb,ll t){
  ll i=min(rima,t/ta);
  t-=ta*i;
  i+=min(rimb,t/tb);
  return i;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T;
    cin>>T;
    while(T--){
      vector<ll> tt(2,0);
      ll N,t;
      cin>>N>>t>>tt[0]>>tt[1];
      vector<pair<ll,bool> >p(N);
      vector<ll> k(2,0);
      for(ll i=0;i<N;i++){
          cin>>p[i].second;
          k[p[i].second]++;
      }
      for(ll i=0;i<N;i++)cin>>p[i].first;
      p.push_back({t+1,0});
      sort(p.begin(),p.end());
      ll ma=0;
      ll time=0;
      ma=max(ma,rim(k[0],k[1],tt[0],tt[1],p[0].first-1));
      for(ll i=0;i<N;i++){
        time+=tt[p[i].second];
        k[p[i].second]--;
        if(time>p[i+1].first-1)continue;
        ma=max(ma,i+rim(k[0],k[1],tt[0],tt[1],p[i+1].first-1-time)+1);
      }
      cout<<ma<<'\n';
    }
    return 0;
}