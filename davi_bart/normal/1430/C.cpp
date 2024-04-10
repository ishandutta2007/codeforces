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
  vector<pair<int,int> > v;
  vector<int> p(N);
  for(int i=0;i<N;i++)p[i]=i+1;
  for(int i=0;i<N-1;i++){
    int k=p.back();
    v.push_back({k,0});
    p.pop_back();
    v.back().second=p.back();
    k+=p.back();
    p.pop_back();
    p.push_back((k+1)/2);
  }
  cout<<p[0]<<'\n';
  for(auto x:v){
    cout<<x.first<<" "<<x.second<<'\n';
  }
}
signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  int T;
  cin>>T;
  while(T--)solve();
}