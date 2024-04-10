#include <iostream>
#include <cstring>

const int MOD=998244353;

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

std::string N;

int num,den;

int dp[101][20][2][1<<4][1<<4];

int solve(int index,int rem,int qr,int aseen,int bseen){
  if(index==N.size()){
    return rem==0&&(aseen&bseen);
  }
  if(rem<-den||rem>num) return 0;
  int& res=dp[index][rem+den][qr][aseen][bseen];
  if(res!=-1){
    return res;
  }
  res=0;
  for(int a=0;a<10;a++){
    for(int b=0;b<10;b++){
      if(!qr&&b>N[index]-'0') continue;
      int aseen2=aseen,bseen2=bseen;
      if(a>0&&a%num==0) aseen2|=(1<<(a/num-1));
      if(b>0&&b%den==0) bseen2|=(1<<(b/den-1));
      res=(res+solve(index+1,rem*10+den*a-num*b,qr||(b<N[index]-'0'),aseen2&15,bseen2))%MOD;
    }
  }
  return res;
}

int main(){
  std::cin>>N;
  int ans=0;
  for(int i=0;i<N.size();i++){
    ans=(ans*10LL+(N[i]-'0'))%MOD;
  }
  for(num=1;num<=9;num++){
    for(den=num+1;den<=9;den++){
      if(gcd(num,den)!=1) continue;
      memset(dp,-1,sizeof(dp));
      int tmp=solve(0,0,0,0,0);
      //printf("%d/%d: %d\n",num,den,tmp);
      ans=(ans+tmp*2LL)%MOD;
    }
  }
  printf("%d\n",ans);
  return 0;
}