#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int N;
  cin>>N;
  vector<pair<int,int> > ans;
  for(int j=0;j<20;j++){
    int k=1<<j;
    for(int i=0;i<N-2*k+1;i+=2*k){
      for(int h=i;h<i+k;h++){
        ans.push_back({h,h+k});
      }
    }
  }
  int x=1;
  while(2*x<=N)x*=2;
  int q=N;
  N=x;
  for(int j=0;j<20;j++){
    int k=1<<j;
    for(int i=0;i<N-2*k+1;i+=2*k){
      for(int h=i;h<i+k;h++){
        ans.push_back({q-N+h,q-N+h+k});
      }
    }
  }
  cout<<ans.size()<<'\n';
  for(auto &[a,b]:ans){
    cout<<a+1<<" "<<b+1<<'\n';
  }
}