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
  vector<pair<int,int> >v;
  v.pb({-10,0});
  v.pb({1e9,0});

  for(int i=1;i<=N;i++){
    int a;
    cin>>a;
    v.push_back({a,i});
  }
  sort(v.begin(),v.end());
  for(int i=1;i<=N;i++){
    if(v[i].fi!=v[i-1].fi && v[i].fi!=v[i+1].fi){
      cout<<v[i].se<<'\n';
      return;
    }
  }
  cout<<-1<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T=1;
  cin>>T;
  while(T--)solve();
}