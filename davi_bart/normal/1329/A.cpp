#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<ll> v;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll N,M;
		cin>>N>>M;
		ll tot=0;
		for(ll i=0;i<M;i++){
      ll a;
      cin>>a;
      v.push_back(a);
      tot+=a;
		}
		if(tot<N){
      cout<<-1;
      return 0;
		}
		vector<ll> sol;
		for(ll i=0;i<M;i++){
      if(v[i]>(N-i)){
        cout<<-1;
        return 0;
      }
      sol.push_back(i);
		}
		ll l=N;
		for(ll i=sol.size()-1;i>=0;i--){
      if((sol[i]+v[i]-1)>=(l-1))break;
      sol[i]=l-v[i];
      l=sol[i];
		}
		for(ll i=0;i<sol.size();i++)cout<<sol[i]+1<<" ";
    return 0;
}