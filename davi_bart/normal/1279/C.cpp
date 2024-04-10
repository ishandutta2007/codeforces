#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>pos(100009);
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T;
    cin>>T;
    while(T--){
      fill(pos.begin(),pos.end(),0);
      ll N,M;
      cin>>N>>M;
      ll tot=0;
      for(ll i=0;i<N;i++){
        ll a;
        cin>>a;
        pos[a]=i;
      }
      ll l=-1;
      for(ll i=0;i<M;i++){
        ll o;
        cin>>o;
        if(pos[o]<l){
          tot++;
          continue;
        }
        l=pos[o];
        tot+=(pos[o]-i)*2+1;
      }
      cout<<tot<<'\n';
    }
    return 0;
}