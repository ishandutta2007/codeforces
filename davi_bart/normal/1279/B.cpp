#pragma GCC optimize("Ofast")
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
      ll som=0;
      vector<ll> p(N);
      for(ll i=0;i<N;i++){
        cin>>p[i];
        som+=p[i];
      }
      if(som<=K){
        cout<<0<<'\n';
        continue;
      }
      ll ma=0,pos=-1;
      som=0;
      for(ll i=0;i<N;i++){
        if(p[i]>ma){
          ma=p[i];
          pos=i;
        }
        som+=p[i];
        if(som>K){
            break;
        }
      }
      cout<<pos+1<<'\n';
    }
    return 0;
}