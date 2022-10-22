#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> sol,v;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll N;
    cin>>N;
    for(ll i=0;i<N;i++){
      ll a;
      cin>>a;
      v.push_back(a);
    }
    ll ma=0;
    for(ll i=0;i<N;i++){
      /*if(v[i]==0){
        sol.push_back(ma);
        continue;
      }
      if(v[i]<0){
        sol.push_back(v[i]+ma);
        continue;
      }*/
      sol.push_back(v[i]+ma);
      ma=max(ma,sol.back());
    }
    for(ll i=0;i<sol.size();i++)cout<<sol[i]<<" ";
    return 0;
}