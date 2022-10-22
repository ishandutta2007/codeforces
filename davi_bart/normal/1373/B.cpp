#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  string a;
  cin>>a;
  int x[2]={0,0};
  for(int i=0;i<a.size();i++){
    x[(a[i]-'0')%2]++;
  }
  int t=min(x[0],x[1]);
  if(t%2)cout<<"DA"<<'\n';
  else cout<<"NET\n";
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}