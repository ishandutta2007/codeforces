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
  vector<int> prec(N),succ(N);
  stack<pair<int,int> >mi;
  mi.push({-10,-1});
  for(int i=0;i<N;i++){
    while(mi.top().fi>=v[i])mi.pop();
    prec[i]=mi.top().se;
    mi.push({v[i],i});
  }
  while(mi.size())mi.pop();
  mi.push({-10,N});
  for(int i=N-1;i>=0;i--){
    while(mi.top().fi>=v[i])mi.pop();
    succ[i]=mi.top().se;
    mi.push({v[i],i});
  }
  vector<int> time;
  for(int i=0;i<N;i++)time.pb(succ[i]-prec[i]-1);
  for(int i=0;i<N;i++)time[i]=N-time[i];
  vector<pair<int,int> >k;
  for(int i=0;i<N;i++)k.pb({v[i],time[i]});
  sort(k.begin(),k.end());
  string ans="";
  int ma=0;
  for(int i=0;i<N;i++){
    if(k[i].fi!=i+1)ma=1e18;
    ma=max(ma,k[i].se);
    if(ma==i)ans+='1';
    else ans+='0';
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}