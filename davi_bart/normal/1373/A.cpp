#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int a,b,c;
  cin>>a>>b>>c;
  if(a<c)cout<<1<<" ";
  else cout<<-1<<" ";
  if(a*b<=c)cout<<-1<<'\n';
  else cout<<b<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}