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
  for(int i=0;i<N;i++)cin>>v[i];
  vector<pair<pair<int,int>,int> >op;
  if(N%2){
    for(int i=0;i<N-2;i+=2){
      op.push_back({{i,i+1},i+2});
    }
    for(int i=0;i<N-2;i+=2){
      op.push_back({{i,i+1},N-1});
    }
    cout<<"YES"<<'\n';
    cout<<op.size()<<'\n';
    for(auto x:op)cout<<x.fi.fi+1<<" "<<x.fi.se+1<<" "<<x.se+1<<'\n';
    return;
  }
  int x=0;
  for(int i=0;i<N-1;i++)x^=v[i];
  if(x!=v[N-1]){
    cout<<"NO"<<'\n';
    return;
  }
  for(int i=0;i<N-2;i+=2){
      op.push_back({{i,i+1},i+2});
    }
    for(int i=0;i<N-2;i+=2){
      op.push_back({{i,i+1},N-2});
    }
    cout<<"YES"<<'\n';
    cout<<op.size()<<'\n';
    for(auto x:op)cout<<x.fi.fi+1<<" "<<x.fi.se+1<<" "<<x.se+1<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int T=1;
  //cin>>T;
  while(T--)solve();
}