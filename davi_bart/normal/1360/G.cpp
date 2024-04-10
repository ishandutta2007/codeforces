#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define o_set tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  bool sol[100][100];
void solve(){
  int N,M,A,B;
  cin>>N>>M>>A>>B;
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++)sol[i][j]=0;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<A;j++)sol[i][j]=1;
  }
  for(int i=0;i<N;i++){
    rotate(sol[i],sol[i]+i*A/B,sol[i]+M);
  }
  for(int i=0;i<M;i++){
      int t=0;
    for(int j=0;j<N;j++){
      t+=sol[j][i];
    }
    if(t!=B){
      cout<<"NO\n";
      return ;
    }
  }
  cout<<"YES\n";
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++)cout<<sol[i][j];
    cout<<'\n';
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