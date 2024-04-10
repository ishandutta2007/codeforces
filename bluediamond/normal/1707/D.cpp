#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int M;
const int FACTN=2000+7;
int pw(int a,int b){
  int r=1;
  while(b){
    if(b&1)r=r*(ll)a%M;
    a=a*(ll)a%M;;
    b/=2;
  }
  return r;
}
int dv(int a,int b){
  return a*(ll)pw(b,M-2)%M;
}
int fact[FACTN],ifact[FACTN];
void computeFACT(){
  fact[0]=1;
  for(int i=1;i<FACTN;i++)fact[i]=fact[i-1]*(ll)i%M;
  ifact[FACTN-1]=dv(1,fact[FACTN-1]);
  for(int i=FACTN-2;i>=0;i--)ifact[i]=ifact[i+1]*(ll)(i+1)%M;
}
int comb(int n,int k) {
  return fact[n]*(ll)ifact[k]%M*(ll)ifact[n-k]%M;
}
const int N=2000+7;
vector<int> g[N];
int n,dp[N][N],print[N],pref[N][N],kek[N],val[N][N];
void dfs(int a,int p=-1) {
  vector<int> kids;
  for (auto &b:g[a]){
    if(b!=p){
      kids.push_back(b);
      dfs(b,a);
    }
  }
  g[a]=kids;
  for (int i=1;i<=n;i++){
    kek[i]=1;
    for (auto &b : g[a]) {
      kek[i]=kek[i]*(ll)pref[b][i]%M;
    }
    dp[a][i]=1;
    for (auto &b:g[a]){
      dp[a][i]=dp[a][i]*(ll)pref[b][i]%M;
    }

  }

  if(a>1){
    for (int j=1;j<=n;j++) {
      for (int it=0;it<(int)g[a].size();it++) {
        val[it][j]=1;
      }
    }
    for (int j=1;j<=n;j++) {
      int prod=1;
      for (int it=0;it<(int)g[a].size();it++) {
        val[it][j]=val[it][j]*(ll)prod%M;
        prod=prod*(ll)pref[g[a][it]][j]%M;
      }
      prod=1;
      for (int it=(int)g[a].size()-1;it>=0;it--) {
        val[it][j]=val[it][j]*(ll)prod%M;
        prod=prod*(ll)pref[g[a][it]][j]%M;
      }
    }
    for (int it=0;it<(int)g[a].size();it++){
      int x=0;
      for (int i=1;i<=n;i++) {
        dp[a][i]=(dp[a][i]+x*(ll)dp[g[a][it]][i])%M;
        x+=val[it][i];
        if(x>=M)x-=M;
      }
    }
  }

  for (int i=1;i<=n;i++){
    pref[a][i]=pref[a][i-1]+dp[a][i];
    if(pref[a][i]>=M)pref[a][i]-=M;
  }
}
int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin>>n>>M;
  computeFACT();
  for (int i=1;i<n;i++) {
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1);
  for (int i=1;i<n;i++){
    print[i]=dp[1][i];
    for(int j=1;j<i;j++) {
      print[i]=(print[i]-print[j]*(ll)comb(i,j))%M;
      if(print[i]<0)print[i]+=M;
    }
    cout<<print[i]<<" ";
  }
  cout<<"\n";
}