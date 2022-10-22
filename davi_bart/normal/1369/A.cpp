#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  if(N%4==0)cout<<"YES\n";
  else cout<<"NO\n";
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
}