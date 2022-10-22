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
  int k=N;
  vector<pair<int,int> > d;
  int tot=0;
  for(int i=2;i*i<=N;i++){
    if(N%i==0)d.pb({0,i});
    while(N%i==0){
      N/=i;
      d.back().fi++;
      tot++;
    }
  }
  if(N>1){
      tot++;
      d.pb({1,N});
  }
  sort(d.begin(),d.end());
  cout<<d.back().fi<<'\n';
  for(int j=0;j<d.back().fi-1;j++){
    cout<<d.back().se<<" ";
    k/=d.back().se;
  }
  cout<<k<<'\n';

}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T=1;
  cin>>T;
  while(T--)solve();
}