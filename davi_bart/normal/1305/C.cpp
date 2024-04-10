#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,mod;
vector<ll> v(2000,-1);
vector<ll> p;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>mod;
    bool perso=0;
    for(ll i=0;i<N;i++){
      ll a;
      cin>>a;
      if(v[a%mod]!=-1){
          perso=1;
      }
      v[a%mod]=a;
      p.push_back(a);
    }
    if(perso){
      cout<<0;
      return 0;
    }
    ll ans=1;
    for(int i=0;i<p.size();i++){
      for(int j=i+1;j<p.size();j++){
        ans=(ans*abs(p[i]-p[j]))%mod;
      }
    }
    cout<<ans<<endl;
    return 0;
}