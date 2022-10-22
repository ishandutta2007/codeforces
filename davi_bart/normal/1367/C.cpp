#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,K;
  cin>>N>>K;
  string a;
  cin>>a;
  for(int i=0;i<K;i++)a+='0';
  a+='1';
  int t=0;
  int prec=-K-1;
  for(int i=0;i<a.size();i++){
    if(a[i]=='1'){
      t+=max(0LL,(i-prec)/(K+1)-1);
      prec=i;
    }
  }
  cout<<t<<'\n';
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--){
      solve();
    }
}