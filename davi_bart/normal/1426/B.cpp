#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct mat{
  int a[2][2];
};
void solve(){
  int N,M;
  cin>>N>>M;
  bool ok=0;
  for(int i=0;i<N;i++){
    mat a;
    cin>>a.a[0][0]>>a.a[0][1]>>a.a[1][0]>>a.a[1][1];
    if(a.a[0][1]==a.a[1][0])ok=1;
  }
  if(M%2 || !ok){
    cout<<"NO\n";
    return;
  }
  cout<<"YES\n";
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int T;
  cin>>T;
  while(T--)solve();
}