#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int mod=998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve(){
  int N,M;
  cin>>N>>M;
  vector<int>v,p;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    v.push_back(a);
  }
  for(int i=0;i<M;i++){
    int a;
    cin>>a;
    p.push_back(a);
  }
  int k=0;
  for(int i=0;i<N;i++){
    if(v[i]==p[k])k++;
    if(k==M)break;
  }
  if(k<M){
    cout<<0;
    return;
  }
  for(int i=0;i<N;i++){
    if(v[i]<p[0]){
      cout<<0;
      return;
    }
  }
  int pos=M-1;
  int prec=N;
  int ans=1;
  bool y=0;
  for(int i=N-1;i>=0;i--){
    if(v[i]==p[pos]){
        if(y==0)prec=i;
        y=1;
    }
    if(v[i]<p[pos]){
      if(y==0){
        cout<<0;
        return;
      }
      y=0;
      ans*=prec-i;
      ans%=mod;
      pos--;
      i++;
    }
  }
  cout<<ans;
}
signed main(){
		ios_base::sync_with_stdio(0);cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--){
      solve();
    }
}