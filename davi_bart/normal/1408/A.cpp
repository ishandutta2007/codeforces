#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N;
  cin>>N;
  vector<int>a(N),b(N),c(N);
  for(int &i:a)cin>>i;
  for(int &i:b)cin>>i;
  for(int &i:c)cin>>i;
  vector<int> sol(N);
  int prec=0;
  for(int i=0;i<N-1;i++){
    if(a[i]!=prec)sol[i]=a[i];
    else if(b[i]!=prec)sol[i]=b[i];
    else if(c[i]!=prec)sol[i]=c[i];
    prec=sol[i];
  }
  prec=sol[N-2];
  int i=N-1;
  if(a[i]!=prec && a[i]!=sol[0])sol[i]=a[i];
  else if(b[i]!=prec && b[i]!=sol[0])sol[i]=b[i];
  else if(c[i]!=prec && c[i]!=sol[0])sol[i]=c[i];
  for(int i:sol)cout<<i<<" ";
  cout<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}