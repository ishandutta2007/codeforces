#include <cstdio>
#include <stdint.h>
#include <algorithm>

const int64_t INF=2e14;

int64_t as[5005];

int64_t dp[2][5005][3];
//0: no house at end
//1: house at end
//2: house right before end

int get_height(int i,int k){
  switch(k){
  case 0:return as[i];
  case 1:return as[i];
  case 2:return std::min(as[i],as[i-1]-1);
  }
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&as[i]);
  }
  int64_t (*curr)[3]=dp[0];
  int64_t (*next)[3]=dp[1];
  for(int64_t j=0;j<=N;j++){
    for(int64_t k=0;k<3;k++){
      curr[j][k]=INF;
      next[j][k]=INF;
    }
  }
  curr[0][0]=0;
  for(int64_t i=1;i<=N;i++){
    for(int64_t j=0;j<=i;j++){
      //no added house
      next[j][2]=curr[j][1]+std::max<int64_t>(0,as[i]-as[i-1]+1);
      next[j][0]=std::min(curr[j][0],curr[j][2]);
      ///add house
      if(j){
	next[j][1]=std::min(curr[j-1][0]+std::max<int64_t>(0,as[i-1]-as[i]+1),
			     curr[j-1][2]+std::max<int64_t>(0,std::min(as[i-1],as[i-2]-1)-as[i]+1));
      }
      /*
	if(next[j][0]<INF) printf("dp[%I64d][%I64d][0]=%I64d\n",i,j,next[j][0]);
	if(next[j][1]<INF) printf("dp[%I64d][%I64d][1]=%I64d\n",i,j,next[j][1]);
	if(next[j][2]<INF) printf("dp[%I64d][%I64d][2]=%I64d\n",i,j,next[j][2]);
      */
    }
    std::swap(curr,next);
  }
  for(int64_t k=1;k<=(N+1)/2;k++){
    if(k>1) printf(" ");
    printf("%I64d",*std::min_element(curr[k],curr[k]+3));
  }
  printf("\n");
  return 0;
}