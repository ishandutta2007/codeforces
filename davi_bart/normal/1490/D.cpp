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
vector<int> k;
vector<int> ans(200000);
void sol(int a,int b,int o){
  if(b<=a)return;
  int pos,ma=0;
  for(int i=a;i<b;i++){
    if(k[i]>ma){
      ma=k[i];
      pos=i;
    }
  }
  ans[pos]=o;
  sol(a,pos,o+1);
  sol(pos+1,b,o+1);
}
void solve(){
  int N;
  cin>>N;
  vector<int> v(N);
  for(int &i:v)cin>>i;
  k=v;
  sol(0,N,0);
  for(int i=0;i<N;i++)cout<<ans[i]<<' ';
  cout<<'\n';
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  int T;
  cin>>T;
  while(T--)solve();
}