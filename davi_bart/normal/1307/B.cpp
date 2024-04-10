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
      ll N,X;
      cin>>N>>X;
      ll mi=1000000000;
      for(ll i=0;i<N;i++){
        ll a;
        cin>>a;
        if(a==X)mi=1;
        else if(a>X)mi=min(mi,(ll)2);
        else mi=min(mi,X/a+(X%a>0));
      }
      cout<<mi<<'\n';
    }
    return 0;
}