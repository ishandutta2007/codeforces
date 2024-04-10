#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,K;
  cin>>N>>K;
  int a[N][N];
  for(int i=0;i<N;i++)for(int j=0;j<N;j++)a[i][j]=0;
  int x=0,y=0;
  for(int i=0;i<K;i++){
    a[x][y]=1;
    x++;
    if(x==N){x=0;y++;}
  }
  for(int i=0;i<N;i++)rotate(a[i],a[i]+i,a[i]+N);
  int ma=0,mi=1e9;
  for(int i=0;i<N;i++){
    int c=0;
    for(int j=0;j<N;j++)c+=a[i][j];
    mi=min(mi,c);
    ma=max(ma,c);
  }
  int tot=(ma-mi)*(ma-mi);
  ma=0,mi=1e9;
  for(int i=0;i<N;i++){
    int c=0;
    for(int j=0;j<N;j++)c+=a[j][i];
    mi=min(mi,c);
    ma=max(ma,c);
  }
  tot+=(ma-mi)*(ma-mi);
  cout<<tot<<'\n';
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)cout<<a[i][j];
    cout<<'\n';
  }
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}