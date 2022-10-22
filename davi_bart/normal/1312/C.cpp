#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T;
    cin>>T;
    while(T--){
      ll N,K;
      cin>>N>>K;
      vector<ll> pot;
      vector<bool> vis(100,0);
      pot.push_back(1);
      for(ll i=0;;i++){
        ll k=pot.back();
        k*=K;
        if(k<=1e16)pot.push_back(k);
        else break;
      }
      ll ma=pot.size()-1;
      vector<ll> p;
      for(ll i=0;i<N;i++){
        ll a;
        cin>>a;
        p.push_back(a);
      }
      bool perso=0;
      for(ll i=0;i<N;i++){
        ll g=ma;
        while(p[i]>0 && g>=0){
          if(pot[g]<=p[i]){
            if(vis[g]){
              perso=1;
              break;
            }
            p[i]-=pot[g];
            vis[g]=1;
          }
          g--;
        }
        if(p[i]>0)perso=1;
      }
      if(perso)cout<<"NO"<<'\n';
      else cout<<"YES"<<'\n';
    }
    return 0;
}