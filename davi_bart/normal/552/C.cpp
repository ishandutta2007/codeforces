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
  int N,M;
  cin>>M>>N;
  vector<int> v;
  while(N){
    v.pb(N%M);
    N/=M;
  }
  v.pb(0);
  v.pb(0);
  v.pb(0);
  v.pb(0);
  for(int i=0;i<v.size();i++){
      if(v[i]>=M)v[i+1]++;
    v[i]%=M;
    if(v[i]<=1)continue;
    if(v[i]==M-1){
      v[i+1]++;
      continue;
    }
    cout<<"NO";
    return ;
  }
  cout<<"YES";
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T=1;
  //cin>>T;
  while(T--){
    solve();
  }
}