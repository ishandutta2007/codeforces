#include <iostream>
#include <cstring>

const int MOD=1e9+7;

int dp[2001][2001][2][2];

std::string A,B;
int M,D;

int solve(int pos,int rem,int ql,int qr){
  if(pos==A.size()) return rem==0;
  if(dp[pos][rem][ql][qr]!=-1)return dp[pos][rem][ql][qr];
  int ans=0;
  for(int c='0';c<='9';c++){
    if(!ql&&c<A[pos]) continue;
    if(!qr&&c>B[pos]) continue;
    if((pos%2)^(c-'0'==D)) continue;
    ans=(ans+solve(pos+1,(rem*10+(c-'0'))%M,ql||c>A[pos],qr||c<B[pos]))%MOD;
  }
  return dp[pos][rem][ql][qr]=ans;
}

int main(){
  std::cin>>M>>D;
  std::cin>>A>>B;
  memset(dp,-1,sizeof dp);
  std::cout<<solve(0,0,0,0)<<std::endl;
  return 0;
}