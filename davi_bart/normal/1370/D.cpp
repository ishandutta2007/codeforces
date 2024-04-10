#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int N,K;
vector<int> v;
bool c(int x){
  int p=0;
  for(int i=0;i<N;i++){
    if(p%2)p++;
    else if(v[i]<=x)p++;
  }
  if(p>=K)return 1;
  p=0;
  for(int i=0;i<N;i++){
    if(p%2==0)p++;
    else if(v[i]<=x)p++;
  }
  if(p>=K)return 1;
  return 0;
}
void solve(){
  cin>>N>>K;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    v.push_back(a);
  }
  int l=0,r=2e9;
  while(l<r-1){
    int m=(l+r)/2;
    if(c(m))r=m;
    else l=m;
  }
  cout<<l+1<<'\n';
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
}