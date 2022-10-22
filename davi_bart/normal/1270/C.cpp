#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T;
    cin>>T;
    while(T--){
      ll N;
      cin>>N;
      ll s=0,x=0;
      for(ll i=0;i<N;i++){
        ll a;
        cin>>a;
        s+=a;
        x^=a;
      }
      if(s==2*x){
        cout<<0<<'\n'<<'\n';
        continue;
      }
      s+=x;
      cout<<2<<'\n'<<x<<" "<<s<<'\n';
    }
    return 0;
}