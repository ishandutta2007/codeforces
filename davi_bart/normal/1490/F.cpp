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
  map<int,int> v;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    v[a]++;
  }
  vector<int> p;
  p.pb(0);
  for(auto a:v)p.pb(a.se);
  sort(p.begin(),p.end());
  int mi=1000000000;


  vector<int> x=p;
  for(int i=1;i<p.size();i++){
    x[i]+=x[i-1];
  }


  for(int i=0;i<p.size();i++){
    int cur=p[i];
    int ans=0;
    if(i)ans+=x[i-1];

    ans+=x.back()-ans-(p.size()-i)*cur;
    mi=min(mi,ans);
  }
  cout<<mi<<'\n';

}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}