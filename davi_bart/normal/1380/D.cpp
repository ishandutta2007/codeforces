#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,M,x,y,k;
  cin>>N>>M>>x>>k>>y;
  vector<int> a(N),b(M);
  for(int &i:a)cin>>i;
  for(int &i:b)cin>>i;
  int pos=0;
  int tot=0;
  vector<vector<int> >g;
  g.push_back(vector<int>());
  for(int i=0;i<N;i++){
    if(pos<M && a[i]==b[pos]){
        pos++;
        g.push_back(vector<int>());
        continue;
    }
    g.back().push_back(a[i]);
  }
  if(pos!=M){
    cout<<-1;
    return;
  }
  for(int i=0;i<g.size();i++){
    if(!g[i].size())continue;
    int mi=1e18;
    if(k<=g[i].size()){
        mi=min(mi,(int)g[i].size()/k*x+(int)(g[i].size()%k)*y);
        mi=min(mi,x+(int)(g[i].size()-k)*y);
    }
    sort(g[i].begin(),g[i].end());
    if((i>0 && g[i].back()<b[i-1]) || (i<M && g[i].back()<b[i]))mi=min(mi,(int)g[i].size()*y);
    if(mi==1e18){
      cout<<-1;
      return;
    }
    tot+=mi;
  }
  cout<<tot;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
}