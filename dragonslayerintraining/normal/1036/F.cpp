#include <cstdio>
#include <stdint.h>
#include <cmath>

bool isprime[60];
int64_t mu[60];

int64_t hs[60];

int64_t ipow(int64_t base,int64_t exp){
  int64_t ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1){
      if(ac>(int64_t)2e18/base) return 2e18;
      ac*=base;
    }
    if(base>(int64_t)2e18/base) base=2e18;
    base*=base;
  }
  return ac;
}

int64_t query(int64_t N){
  int64_t ans=N-1;
  //printf("%I64d: %I64d\n",N,N-1);
  for(int64_t k=2;k<60;k++){
    if(mu[k]){
      int64_t low=1,high=hs[k];
      while(high-low>1){
	int64_t mid=(low+high)/2;
	if(ipow(mid,k)<=N){
	  low=mid;
	}else{
	  high=mid;
	}
      }
      //printf("%I64d: %c%I64d\n",k,(mu[k]>0)?'+':'-',low-1);
      ans+=mu[k]*(low-1);
    }
  }
  return ans;
}

int main(){
  for(int64_t i=2;i<60;i++){
    isprime[i]=true;
    mu[i]=1;
  }
  for(int64_t i=2;i<60;i++){
    if(isprime[i]){
      for(int64_t k=i*2;k<60;k+=i){
	isprime[k]=false;
      }
      for(int64_t k=i;k<60;k+=i){
	mu[k]*=-1;
      }
      for(int64_t k=i*i;k<60;k+=i*i){
	mu[k]=0;
      }
    }
  }
  /*
  for(int64_t i=2;i<60;i++){
    printf("mu[%I64d]=%I64d\n",i,mu[i]);
  }
  */
  for(int64_t i=2;i<60;i++){
    hs[i]=pow(1e18,1.0/i);
    while(ipow(hs[i],i)>(int64_t)1e18) hs[i]--;
    while(ipow(hs[i],i)<=(int64_t)1e18) hs[i]++;
    //printf("%I64d: %I64d\n",i,hs[i]);
  }
  int64_t T;
  scanf("%I64d",&T);
  while(T-->0){
    int64_t N;
    scanf("%I64d",&N);
    printf("%I64d\n",query(N));
  }
  return 0;
}