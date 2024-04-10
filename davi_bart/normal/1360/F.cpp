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
  int N,M;
  cin>>N>>M;
  vector<string>a;
  for(int i=0;i<N;i++){
    string s;
    cin>>s;
    a.push_back(s);
  }
  string v;
  for(int i=0;i<M;i++){
    v=a[0];
    v[i]='#';
    for(int j=0;j<N;j++){
      int t=0;
      for(int h=0;h<M;h++){
        if(v[h]!='#' && a[j][h]!=v[h])t++;
      }
      if(t>1)break;
      if(t==1){
        for(int h=0;h<M;h++){
          if(v[h]=='#')v[h]=a[j][h];
        }
      }
      if(j==N-1){
        for(int k=0;k<M;k++)if(v[k]=='#')v[k]='a';
        cout<<v<<'\n';
        return ;
      }
    }
  }
  cout<<-1<<'\n';
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
		int T;
		cin>>T;
		while(T--)solve();
}