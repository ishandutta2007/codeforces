#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  string a;
  cin>>a;
  int r=0;
  int c=0;
  int mi=0;
  for(int i=0;i<a.size();i++){
    if(a[i]=='-')c--;
    else c++;
    if(c<mi){
      mi--;
      r+=i+1;
    }
  }
  cout<<r+a.size()<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}