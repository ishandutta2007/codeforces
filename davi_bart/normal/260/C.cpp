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
  int N,x;
  cin>>N>>x;
  x--;
  vector<int> v(N);
  for(int &i:v)cin>>i;
  int mi=1e18;
  int pos;
  for(int i=x;i>=0;i--){
    if(v[i]<mi){
      mi=v[i];
      pos=i;
    }
  }
  for(int i=N-1;i>x;i--){
    if(v[i]<mi){
      mi=v[i];
      pos=i;
    }
  }

  int t=0;
  for(int i=0;i<pos;i++){
    t+=v[pos];
    if(i<=x && x<pos){
        v[i]-=v[pos]+1;
        t++;
    }
    else v[i]-=v[pos];
  }
  for(int i=pos+1;i<N;i++){
    t+=v[pos];
    if(i<=x || x<pos){
        v[i]-=v[pos]+1;
        t++;
    }
    else v[i]-=v[pos];
  }
  v[pos]+=t;
  for(int i:v)cout<<i<<" ";
}