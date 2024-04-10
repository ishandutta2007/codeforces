#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int> k;
int memo[200010][2];
int sol(int pos,int buco){
  if(pos>=k.size()){
      if(buco)return 0;
      return 1e18;
  }
  if(memo[pos][buco]!=-1)return memo[pos][buco];
  int mi=1e18;
  mi=min(mi,sol(pos+2,buco)+k[pos]);
  if(buco==0)mi=min(mi,sol(pos+3,1)+k[pos]);
  return memo[pos][buco]=mi;
}
void solve(){
  int N;
  cin>>N;
  for(int i=0;i<N+5;i++){
    memo[i][0]=memo[i][1]=-1;
  }
  k.resize(N);
  int tot=0;
  for(int &i:k){
      cin>>i;
      tot+=i;
  }
  cout<<tot-min({sol(0,0),sol(1,0),sol(2,1)});

}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
}