#include <cstdio>
#include <algorithm>
#include <functional>

int N;
double ps[101];

double dp[2]={1,0};

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%lf",&ps[i]);
  }
  std::sort(ps,ps+N,std::greater<double>());
  double best=0;
  for(int i=0;i<N;i++){
    dp[1]=dp[1]*(1-ps[i])+dp[0]*ps[i];
    dp[0]*=(1-ps[i]);
    best=std::max(best,dp[1]);
  }
  printf("%.10lf\n",best);
  return 0;
}