#include <bits/stdc++.h>

using namespace std;
#define int long long

bool home = 1;
const int N=40+7;
int n,ps[N],where[N][2],m;
string s;

int dp[N][N][N][2];

int solve(int i,int cur,int finito,int ok){
  if(dp[i][cur][finito][ok]!=-1) return dp[i][cur][finito][ok];
  if(cur==m) ok=1;
  int &sol=dp[i][cur][finito][ok];
  sol=0;
  if(i==n){
    sol=(cur==finito&&ok);
    return sol;
  }
  for(int x=0;x<2;x++){
    sol+=solve(i+1,where[cur][x],finito,ok);
  }
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif

  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      for(int k=0;k<N;k++){
        dp[i][j][k][0]=dp[i][j][k][1]=-1;
      }
    }
  }

  cin>>n>>s;

  m=(int)s.size();
  ps[0]=0;
  int cur=0;
  for(int i=1;i<m;i++){
    while(cur&&s[i]!=s[cur]){
      cur=ps[cur-1];
    }
    if(s[i]==s[cur]){
      cur++;
    }
    ps[i]=cur;
  }

  for(int curi=0;curi<=m;curi++){
    for(int x=0;x<2;x++){
      int cur=curi;
      if(cur==m){
        cur=ps[cur-1];
      }
      while(cur&&x!=s[cur]-'0'){
        cur=ps[cur-1];
      }
      if(x==s[cur]-'0'){
        cur++;
      }
      where[curi][x]=cur;
    }
  }

 /** for(int cur=0;cur<=m;cur++){
    for(int x=0;x<2;x++){
      cout<<"w["<<cur<<"]["<<x<<"] = "<<where[cur][x]<<"\n";
    }
  }
  exit(0);**/


  int sol=0;

  for(int cur=0;cur<=m;cur++){
    sol+=solve(0,cur,cur,0);
  }

  cout<<sol<<"\n";

  exit(0);
  for(int i=0;i<m;i++){
    cout<<ps[i]<<" ";
  }
  cout<<"\n";


  return 0;
}