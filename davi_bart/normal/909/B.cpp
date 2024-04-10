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

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int N;
  cin>>N;
  int t=0;
  for(int i=1;i<=N;i++){
    t+=min(i,N-i+1);
  }
  cout<<t;

}