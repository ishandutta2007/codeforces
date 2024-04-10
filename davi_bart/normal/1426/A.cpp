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
  int N,x;
  cin>>N>>x;
  if(N<3){
      cout<<"1\n";
      return;
  }
  N-=2;
  for(int i=2;i<1000;i++){
    if(N<=x){
      cout<<i<<'\n';
      return;
    }
    N-=x;
  }
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int T;
  cin>>T;
  while(T--)solve();
}