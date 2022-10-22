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
  int N,K;
  cin>>N>>K;
  vector<pair<int,int> >v(N);
  for(auto &i:v)cin>>i.fi>>i.se;
  int mi=1e9;
  for(int i=0;i<N;i++){
      bool ok=1;
      for(int j=0;j<N;j++){
        if(abs(v[i].fi-v[j].fi)+abs(v[i].se-v[j].se)>K)ok=0;
      }
      if(ok){
        cout<<1<<'\n';
        return;
      }
  }
  cout<<-1<<'\n';
  return;

}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}