#include <iostream>
#include <cstring>

const int MOD=998244353;

int pow10[20];

std::string L,R;
int K;

struct CntSum{
  int cnt,sum;
  CntSum(int cnt,int sum):cnt(cnt),sum(sum){
  }
  CntSum():CntSum(0,0){
  }
}dp[20][2][2][2][1<<10];
bool vis[20][2][2][2][1<<10];

int pop(int mask){
  int cnt=0;
  while(mask){
    cnt++;
    mask-=(mask&-mask);
  }
  return cnt;
}

CntSum solve(int index,int ql,int qr,int nz,int mask){
  if(index==R.size()){
    return {pop(mask)<=K,0};
  }
  auto& res=dp[index][ql][qr][nz][mask];
  if(vis[index][ql][qr][nz][mask]){
    return res;
  }
  vis[index][ql][qr][nz][mask]=true;
  for(int d=0;d<10;d++){
    if(!ql&&d+'0'<L[index]) continue;
    if(!qr&&d+'0'>R[index]) continue;
    auto tmp=solve(index+1,ql||d+'0'>L[index],qr||d+'0'<R[index],nz||d,mask|((nz||d)<<d));
    res.cnt=(res.cnt+tmp.cnt)%MOD;
    res.sum=(res.sum+tmp.sum+1LL*tmp.cnt*d*pow10[R.size()-index-1])%MOD;
  }
  return res;
}

int main(){
  pow10[0]=1;
  for(int i=1;i<20;i++){
    pow10[i]=10LL*pow10[i-1]%MOD;
  }
  std::cin>>L>>R>>K;
  if(L.size()<R.size()){
    L=std::string(R.size()-L.size(),'0')+L;
  }
  printf("%d\n",solve(0,0,0,0,0).sum);
}