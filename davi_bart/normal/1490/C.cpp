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
set<int> cubo;
void solve(){
  int N;
  cin>>N;
  for(int i=1;i<10010;i++){
    int x=N-i*i*i;
    if(cubo.find(x)!=cubo.end()){
      cout<<"YES\n";
      return;
    }
  }
  cout<<"NO\n";
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  for(int i=1;i<10010;i++){
    cubo.insert(i*i*i);
  }
  int T;
  cin>>T;
  while(T--)solve();
}