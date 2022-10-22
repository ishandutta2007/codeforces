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
  int mi=1e9;
  for(int i=1;i<100000;i++){
    mi=min(mi,(N+i-1)/(i)+i-1);
  }
  cout<<mi-1<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int T;
  cin>>T;
  while(T--)solve();
}