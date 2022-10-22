#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  int a[N];
  for(int i=0;i<N;i++)cin>>a[i];
  if(a[0]<a[N-1])cout<<"YES\n";
  else cout<<"NO\n";
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}