#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define o_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<vector<int> > v;
  int N,K;
int query(int sx,int dx){
  int t=0;
  for(int i=sx;i<dx;i++){
      t+=v[i].size();
  }
  cout<<"? "<<t<<" ";
  for(int i=sx;i<dx;i++){
    for(int j=0;j<v[i].size();j++){
      cout<<v[i][j]<<" ";
    }
  }
  cout<<endl;
  int a;
  cin>>a;
  return a;
}
int query1(int pos){
  int t=0;
  set<int> m;
  for(int i=0;i<N;i++){
      m.insert(i+1);
  }
    for(int j=0;j<v[pos].size();j++){
      m.erase(v[pos][j]);
    }
  cout<<"? "<<m.size()<<" ";
  for(int g:m)cout<<g<<" ";
  cout<<endl;
  int a;
  cin>>a;
  return a;
}
void solve(){
  v.clear();
  cin>>N>>K;
  v.resize(K);
  for(int i=0;i<K;i++){
    int a;
    cin>>a;
    while(a--){
      int b;
      cin>>b;
      v[i].push_back(b);
    }
  }if(K==1){
    int x=query1(0);
    cout<<"! "<<x<<endl;
    string l;
    cin>>l;
    //if(l!="Correct")exit(0);
    return ;
  }
  int ma=query(0,K);

  int sx=0,dx=K;
  while(sx<dx-1){
    int m=(sx+dx)/2;
    if(query(sx,m)==ma)dx=m;
    else sx=m;
  }
  int x=query1(sx);
  cout<<"! ";
  for(int i=0;i<K;i++){
    if(i==sx)cout<<x<<" ";
    else cout<<ma<<" ";
  }
  cout<<endl;
  string l;
  cin>>l;
  if(l!="Correct")exit(0);
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}