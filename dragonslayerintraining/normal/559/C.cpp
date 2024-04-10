#include <cstdio>
#include <algorithm>
#include <vector>
#include <stdint.h>

const int64_t MOD=1e9+7;

std::vector<std::pair<int64_t,int64_t> > points;

int64_t dp[2001];

int64_t inv[200001];
int64_t fact[200001];
int64_t invfact[200001];

int64_t combo(int64_t x,int64_t y){
  return fact[x+y]*invfact[x]%MOD*invfact[y]%MOD;
}

int main(){
  inv[1]=1;
  for(int i=2;i<=200000;i++){
    inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
  }
  fact[0]=1;
  invfact[0]=1;
  for(int i=1;i<=200000;i++){
    fact[i]=fact[i-1]*i%MOD;
    invfact[i]=invfact[i-1]*inv[i]%MOD;
  }
  int64_t H,W,N;
  scanf("%I64d %I64d %I64d",&H,&W,&N);
  for(int64_t i=0;i<N;i++){
    int64_t R,C;
    scanf("%I64d %I64d",&R,&C);
    R--,C--;
    points.emplace_back(R,C);
  }
  points.emplace_back(H-1,W-1);
  std::sort(points.begin(),points.end());
  for(int64_t i=0;i<=N;i++){
    for(int64_t j=0;j<i;j++){
      if(points[j].first<=points[i].first&&
	 points[j].second<=points[i].second){
	dp[i]=(dp[i]+dp[j]*combo(points[i].first-points[j].first,points[i].second-points[j].second))%MOD;
      }
    }
    dp[i]=(combo(points[i].first,points[i].second)+MOD-dp[i])%MOD;
  }
  printf("%I64d\n",dp[N]);
  return 0;
}