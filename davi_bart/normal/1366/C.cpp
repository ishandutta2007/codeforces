#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,M;
  cin>>N>>M;
  vector<int> a(N+M+10,0);
  vector<int> b(N+M+10,0);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      int c;
      cin>>c;
      if(c)a[i+j]++;
      else b[i+j]++;
    }
  }
  int tot=0;
  for(int i=0;i<(N+M-1)/2;i++)tot+=min(a[i]+a[N+M-i-2],b[i]+b[N+M-i-2]);
  cout<<tot<<'\n';
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--){
      solve();
    }
}