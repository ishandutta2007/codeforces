#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,M;
  cin>>N>>M;
  bool ok=1;
  int a[N][M];
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>a[i][j];
      int pos=4;
      if(i==0 || i==N-1)pos--;
      if(j==0 || j==M-1)pos--;
      if(a[i][j]>pos)ok=0;
      a[i][j]=pos;
    }
  }
  if(!ok)cout<<"NO\n";
  else{
    cout<<"YES\n";
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++)cout<<a[i][j]<<" ";
      cout<<'\n';
    }
  }
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}