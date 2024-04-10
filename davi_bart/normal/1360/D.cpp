#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define o_set tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int N,K;
  cin>>N>>K;
  if(K>=N){
    cout<<1<<'\n';
    return ;
  }
  vector<int>d;
  for(int i=1;i*i<=N;i++){
    if(N%i==0){
      d.push_back(i);
      if(i*i!=N)d.push_back(N/i);
    }
  }
  sort(d.begin(),d.end());
  for(int i=d.size()-1;i>=0;i--){
    if(d[i]<=K){
      cout<<N/d[i]<<'\n';
      return;
    }
  }
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
		int T;
		cin>>T;
		while(T--)solve();
}