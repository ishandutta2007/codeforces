#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define o_set tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool a[100][100];
int N;
void solve(){
  cin>>N;
  for(int i=0;i<N;i++){
    string p;
    cin>>p;
    for(int j=0;j<N;j++){
        a[i][j]=p[j]-'0';
    }
  }
  for(int i=N-1;i>=0;i--){
    for(int j=0;j<N;j++){
      if(a[i][j]==0 || i==N-1 || j==N-1)continue;
      if(a[i+1][j] || a[i][j+1])continue;
      cout<<"NO\n";
      return ;
    }
  }
  cout<<"YES\n";
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
		int T;
		cin>>T;
		while(T--)solve();
}