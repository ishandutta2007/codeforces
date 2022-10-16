#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int st[400005][1<<5];
int as[5];
int far[1<<5];
int N,K;

void assign(int i){
  for(int j=0;j<K;j++){
    scanf("%d",&as[j]);
  }
  for(int k=0;k<(1<<K);k++){
    int sum=0;
    for(int j=0;j<K;j++){
      if(k&(1<<j)){
	sum+=as[j];
      }else{
	sum-=as[j];
      }
    }
    //printf("st[%d][%d]=%d\n",i+N,k,sum);
    st[i+N][k]=sum;
  }
  for(i+=N;i>1;i>>=1){
    for(int k=0;k<(1<<K);k++){
      st[i>>1][k]=std::max(st[i][k],st[i^1][k]);
    }
  }
}

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    assign(i);
  }
  int Q;
  scanf("%d",&Q);
  int full=(1<<K)-1;
  while(Q-->0){
    int T;
    scanf("%d",&T);
    if(T==1){
      int I;
      scanf("%d",&I);
      I--;
      assign(I);
    }else{
      int L,R;
      scanf("%d %d",&L,&R);
      L--;
      for(int k=0;k<(1<<K);k++){
	far[k]=-INF;
      }
      for(L+=N,R+=N;L<R;L>>=1,R>>=1){
	if(L&1){
	  for(int k=0;k<(1<<K);k++){
	    far[k]=std::max(far[k],st[L][k]);
	  }
	  L++;
	}
	if(R&1){
	  --R;
	  for(int k=0;k<(1<<K);k++){
	    far[k]=std::max(far[k],st[R][k]);
	  }
	}
      }
      int ans=0;
      for(int k=0;k<(1<<K);k++){
	//printf("far[%d]=%d\n",k,far[k]);
	ans=std::max(ans,far[k]+far[k^full]);
      }
      printf("%d\n",ans);
    }
  }
  return 0;
}