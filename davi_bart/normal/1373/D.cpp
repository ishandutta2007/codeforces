#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  vector<int> v(N);
  int tot=0;
  for(int i=0;i<N;i++){
    cin>>v[i];
    if(i%2==0)tot+=v[i];
  }
  int ma=0;
  vector<int> p(N+10,0);
  for(int i=N-2;i>=0;i--){
    int cur=v[i]-v[i+1];
    if(i%2==0)cur=-cur;
    p[i]=max({(ll)0,cur,cur+p[i+2]});
    ma=max(ma,p[i]);
  }
  cout<<tot+ma<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}