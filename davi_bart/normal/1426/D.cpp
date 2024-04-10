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
  set<int> sum={0};
  int cur=0,ans=0;
  for(int i=0;i<N;i++){
    cur+=v[i];
    if(sum.find(cur)!=sum.end()){
      ans++;
      sum.clear();
      sum.insert(0);
      cur=v[i];
    }
    sum.insert(cur);
  }
  cout<<ans;
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int T=1;
  //cin>>T;
  while(T--)solve();
}