#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define o_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--){
    int N,X;
    cin>>N>>X;
    vector<int> v(N+3,0);
    for(int i=0;i<N-1;i++){
      int a,b;
      cin>>a>>b;
      v[a]++;v[b]++;
    }
    if(v[X]<=1){
      cout<<"Ayush"<<'\n';
      continue;
    }
    int p=N-3;
    if(p%2)cout<<"Ayush"<<'\n';
    else cout<<"Ashish"<<'\n';
  }
}