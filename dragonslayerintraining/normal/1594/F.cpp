#include <cstdio>

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    long long S,N,K;
    scanf("%lld %lld %lld",&S,&N,&K);
    if(S==K){
      printf("YES\n");
    }else if(N<=(S%K)*((S/K+2)/2)+(K-S%K)*((S/K+1)/2)-S/K%2){
      printf("NO\n");
    }else{
      printf("YES\n");
    }
  }
}