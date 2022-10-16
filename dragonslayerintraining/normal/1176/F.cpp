#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stdint.h>

const int64_t INF=1e18+7;

int64_t local[4][4][2];//cost taken, cards taken, doubled

int64_t dp[200005][10];//turn, cards played % 10


void setmax(int64_t& x,int64_t y){
  x=std::max(x,y);
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<=N;i++){
    std::fill(dp[i],dp[i]+10,-INF);
  }
  dp[0][0]=0;
  for(int i=0;i<N;i++){
    int K;
    scanf("%d",&K);
    for(int cost=0;cost<4;cost++){
      for(int cards=0;cards<4;cards++){
	for(int dbl=0;dbl<2;dbl++){
	  local[cost][cards][dbl]=-INF;
	}
      }
    }
    for(int cost=0;cost<4;cost++){
      for(int dbl=0;dbl<2;dbl++){
	local[cost][0][dbl]=0;
      }
    }
    while(K--){
      int C,D;
      scanf("%d %d",&C,&D);
      for(int cost=3;cost>=C;cost--){
	for(int cards=3;cards>=1;cards--){
	  setmax(local[cost][cards][0],local[cost-C][cards-1][0]+D);
	  setmax(local[cost][cards][1],local[cost-C][cards-1][1]+D);
	  setmax(local[cost][cards][1],local[cost-C][cards-1][0]+D*2);
	}
      }
    }
    for(int s=0;s<10;s++){
      for(int p=0;p<=3;p++){
	setmax(dp[i+1][(s+p)%10],dp[i][s]+local[3][p][(s+p)/10]);
      }
    }
    /*
    for(int r=0;r<10;r++){
      printf("dp[%d][%d]=%I64d\n",i+1,r,dp[i+1][r]);
    }
    */
  }
  printf("%I64d\n",*std::max_element(dp[N],dp[N]+10));
  return 0;
}