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
void solve(){
    int N;
    cin>>N;
    vector<int> v(N);
    for(int &i:v)cin>>i;
    set<int> ans;
    for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
        ans.insert(v[j]-v[i]);
      }
    }
    cout<<ans.size()<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}