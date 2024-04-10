#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll T;
		cin>>T;
		while(T--){
      ll N,M;
      cin>>N>>M;
      vector<ll>pot(62,0);
      for(ll i=0;i<M;i++){
        ll a;
        cin>>a;
        pot[31-__builtin_clz(a)]++;
      }
      bool perso=0;
      ll tot=0;
      ll rim=0;
      for(ll i=0;i<61;i++){
        ll k=(ll)1<<i;
        if((N&k)>0){
          ll pos=-1;
          for(ll j=i;j<pot.size();j++){
            if(pot[j]>0){
              pos=j;
              break;
            }
          }
          if(pos==-1){
            perso=1;
            break;
          }
          while(pos>i){
            tot++;
            pot[pos]--;
            pot[pos-1]+=2;
            pos--;
          }
          pot[pos]--;
          N-=k;
        }
        rim+=k*pot[i];
        if(rim>=k*2){
            pot[i+1]++;
            rim-=k*2;
        }
      }
      if(perso)cout<<-1<<'\n';
      else cout<<tot<<'\n';
		}
    return 0;
}