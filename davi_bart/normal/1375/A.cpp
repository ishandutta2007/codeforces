#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  vector<int> v(N,0);
  for(int &i:v)cin>>i;
  for(int i=0;i<N;i++){
    if(i%2)cout<<abs(v[i])<<" ";
    else cout<<-abs(v[i])<<" ";
  }
  cout<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}