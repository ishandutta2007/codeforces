#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  string a;
  cin>>a;
  int p=0,r=0,s=0;
  for(int i=0;i<a.size();i++){
    if(a[i]=='P')p++;
    else if(a[i]=='R')r++;
    else s++;
  }
  if(s>=r && s>=p){
    string sol(a.size(),'R');
    cout<<sol<<'\n';
    return;
  }
  if(r>=s && r>=p){
    string sol(a.size(),'P');
    cout<<sol<<'\n';
    return;
  }
  if(p>=s && p>=r){
    string sol(a.size(),'S');
    cout<<sol<<'\n';
    return;
  }
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}