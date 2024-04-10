#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int queryB(int a){
  cout<<"B "<<a<<endl;
  int y;
  cin>>y;
  return y;
}
int queryA(int a){
  cout<<"A "<<a<<endl;
  int y;
  cin>>y;
  return y;
}
void solve(){
  int N;
  cin>>N;
  vector<int> v[N+10];
  for(int i=0;i<N-1;i++){
    int a,b;
    cin>>a>>b;
    v[a].pb(b);
    v[b].pb(a);
  }
  set<int> a,b;
  int k;
  cin>>k;
  for(int i=0;i<k;i++){
    int y;
    cin>>y;
    a.insert(y);
  }
  cin>>k;
  for(int i=0;i<k;i++){
    int y;
    cin>>y;
    b.insert(y);
  }
  vector<bool> vis(N+10,0);
  queue<int> q;
  q.push(queryB(*b.begin()));
  while(!q.empty()){
    int pos=q.front();
    q.pop();
    if(vis[pos])continue;
    vis[pos]=1;
    if(a.count(pos)){
      int q=queryA(pos);
      if(b.count(q)){
        cout<<"C "<<pos<<endl;
        return;
      }
      cout<<"C -1"<<endl;
      return ;
    }
    for(int i:v[pos])q.push(i);
  }
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}