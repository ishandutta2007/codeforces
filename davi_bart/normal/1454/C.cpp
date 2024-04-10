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
void solve(){
  int N;
  cin>>N;
  vector<int>v[N+10];
  int prec=-1;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    v[a].pb(i);
  }
  int mi=1e9;
  for(int i=0;i<=N;i++){
    if(v[i].size()==0)continue;
    int c=0;
    int prec=-1;
    v[i].pb(N);
    for(int j=0;j<v[i].size();j++){
      if(v[i][j]!=prec+1)c++;
      prec=v[i][j];
    }
    mi=min(mi,c);
  }
  cout<<mi<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T=1;
  cin>>T;
  while(T--)solve();
}