#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  int d=0;
  for(int i=2;i*i<=N;i++){
    if(N%i==0){
      d=max({d,i,N/i});
    }
  }
  if(d==0)d=1;
  cout<<d<<" "<<N-d<<"\n";
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}