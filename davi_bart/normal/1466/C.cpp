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
    string a;
    cin>>a;
    int t=0;
    for(int i=1;i<a.size();i++){
      if(a[i]==a[i-1]){
        t++;
        a[i]=')';
      }else if(i>1 && a[i]==a[i-2]){
        t++;
        a[i]=')';
      }
    }
    cout<<t<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}