#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
map<int,int> v;
void solve(){
  v.clear();
  int N,K;
  cin>>N>>K;
  int tot=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(a%K==0)continue;
    int d=K-a%K;
    if(v[d]==0)v[d]=d;
    else v[d]+=K;
    tot=max(tot,v[d]+1);
  }
  cout<<tot<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while(T--)solve();
}