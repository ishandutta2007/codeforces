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
  vector<int> v(N);
  for(int &i:v)cin>>i;
  sort(v.begin(),v.end());
  for(int i=1;i<N;i++){
    if(v[i]==v[i-1]){
        cout<<"YES"<<'\n';
        return;
    }
  }
  cout<<"NO"<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int T;
  cin>>T;
  while(T--)solve();
}