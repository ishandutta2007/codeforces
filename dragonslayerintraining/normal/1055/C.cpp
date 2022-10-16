#include <cstdio>
#include <algorithm>
#include <stdint.h>

const int64_t INF=1e9+7;

int64_t gcd(int64_t a,int64_t b){
  return b?gcd(b,a%b):a;
}

int64_t LA,RA,LB,RB;
int64_t T;
int64_t ans=0;

void improve(int64_t k){
  ans=std::max(ans,std::min(RA+k*T,RB)-std::max(LA+k*T,LB)+1);
}

int main(){
  int64_t TA,TB;
  scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&LA,&RA,&TA,&LB,&RB,&TB);
  T=gcd(TA,TB);
  {
    int64_t low=-INF,high=INF;
    while(high-low>1){
      int64_t mid=(low+high)/2;
      if(RA+mid*T<=RB){
	low=mid;
      }else{
	high=mid;
      }
    }
    //printf("low=%I64d,high=%I64d\n",low,high);
    improve(low);
    improve(high);
  }
  {
    int64_t low=-INF,high=INF;
    while(high-low>1){
      int64_t mid=(low+high)/2;
      if(LA+mid*T<=LB){
	low=mid;
      }else{
	high=mid;
      }
    }
    //printf("low=%I64d,high=%I64d\n",low,high);
    improve(low);
    improve(high);
  }
  printf("%I64d\n",ans);
  return 0;
}