#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int v,c,a,b;;
  cin>>v>>c>>a>>b;
  if(a+b<=v+c && b<=min(v,c))cout<<"Yes"<<'\n';
  else cout<<"No\n";
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}