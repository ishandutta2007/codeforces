#include <cstdio>
#include <algorithm>
#include <stdint.h>

int anc[400002][19];
int64_t weight[400002][19];

int next=2;

const int64_t INF=1e18+7;

int main(){
  for(int k=1;k<19;k++){
    weight[1][k]=INF;
  }
  int Q;
  scanf("%d",&Q);
  int last=0;
  while(Q-->0){
    int64_t T,P,Q;
    scanf("%I64d %I64d %I64d",&T,&P,&Q);
    int64_t R=P^last,W=Q^last;
    //printf("QUERY: %d %d %d\n",T,R,W);
    if(T==1){
      for(int k=18;k>=0;k--){
	int up=anc[R][k];
	if(up&&weight[up][0]<W){
	  R=up;
	}
      }
      if(R&&weight[R][0]<W){
	R=anc[R][0];
      }
      //printf("LINK %d to %d\n",next,R);
      //printf("WEIGHT %d\n",W);
      anc[next][0]=R;
      weight[next][0]=W;
      for(int k=1;k<19;k++){
	int up=anc[next][k-1];
	if(up){
	  anc[next][k]=anc[up][k-1];
	  weight[next][k]=std::min(INF,weight[next][k-1]+weight[up][k-1]);
	}else{
	  anc[next][k]=0;
	  weight[next][k]=INF;
	}
      }
      next++;
    }else{
      last=0;
      for(int k=18;k>=0;k--){
	last<<=1;
	//printf("k=%d last=%d\n",k,last);
	if(R&&weight[R][k]<=W){
	  W-=weight[R][k];
	  R=anc[R][k];
	  last++;
	}
      }
      printf("%d\n",last);
    }
  }
  return 0;
}