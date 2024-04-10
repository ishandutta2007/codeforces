#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int a,b;
  cin>>a>>b;
  b=min(b,a);
  int tot=b*(b+1)/2;
  /*for(int i=1;i<=b;i++){
    if(a%i==0)tot-=i-1;
  }*/
  if(b==a)tot-=b-1;
  cout<<tot<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}