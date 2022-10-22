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
      vector<ll> v;
      for(ll i=0;i<N;i++){
        ll a;
        cin>>a;
        v.push_back(a);
      }
      bool k=0;
      for(ll i=1;i<N;i++){
        if(abs(v[i]-v[i-1])>=2){
          cout<<"YES"<<'\n';
          cout<<i<<" "<<i+1<<'\n';
          k=1;
          break;
        }
      }
      if(k==0)cout<<"NO"<<'\n';
    }
    return 0;
}