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
  int N,K;
  cin>>N>>K;
  vector<int> v(N);
  for(int &i:v)cin>>i;
  sort(v.begin(),v.end());
  for(int i=N-2;i>N-2-K;i--){
    v.back()+=v[i];
  }
  cout<<v.back()<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int T;
  cin>>T;
  while(T--)solve();
}