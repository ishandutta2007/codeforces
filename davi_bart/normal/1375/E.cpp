#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int N;
  cin>>N;
  vector<int> p(N);
  vector<pair<int,int> >k;
  int g=0;
  for(int &i:p){
      cin>>i;
      k.push_back({i,g++});
  }
  sort(k.begin(),k.end());
  for(int i=0;i<N;i++){
    p[k[i].second]=i;
  }
  vector<int> v[1100];
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(p[i]>p[j]){
        v[j].push_back(i);
      }
    }
  }
  vector<pair<int,int> >sol;
  for(int i=N-1;i>0;i--){
    sort(v[i].begin(),v[i].end(),[&](int a,int b){
        return p[a]<p[b];
    });
    for(int j=0;j<v[i].size();j++){
      sol.push_back({i+1,v[i][j]+1});
      swap(p[i],p[v[i][j]]);
    }
  }
  for(int i=1;i<N;i++){
    if(p[i]<p[i-1]){
      cout<<-1;
      return;
    }
  }
  cout<<sol.size()<<'\n';
  for(auto x:sol)cout<<x.second<<" "<<x.first<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T=1;
   // cin>>T;
    while(T--)solve();
}