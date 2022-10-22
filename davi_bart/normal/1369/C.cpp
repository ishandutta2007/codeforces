#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,K;
  cin>>N>>K;
  vector<int> v;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    v.push_back(a);
  }
  vector<int> p(K,0);
  for(int i=0;i<K;i++)cin>>p[i];

  sort(p.begin(),p.end(),greater<int>());
  sort(v.begin(),v.end());
  int tot=0;
  int pos=0;
  while(p.size() && p.back()==1){
    p.pop_back();
    tot+=2*v.back();
    v.pop_back();
  }
  for(int i=0;i<p.size();i++){
    tot+=v[pos]+v[v.size()-i-1];
    pos+=p[i]-1;
    //cout<<tot<<'\n';
  }
  cout<<tot<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T=1;
    cin>>T;
    while(T--)solve();
}