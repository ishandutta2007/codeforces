#include <cstdio>

const int N=500000;
const int SQRT=1000;

int as[N];
int bs[SQRT][SQRT];

int main(){
  int Q;
  scanf("%d",&Q);
  while(Q--){
    int T,X,Y;
    scanf("%d %d %d",&T,&X,&Y);
    if(T==1){
      X--;
      as[X]+=Y;
      for(int i=1;i<SQRT;i++){
	bs[i][X%i]+=Y;
      }
    }else{
      Y=(Y+X-1)%X;
      if(X<SQRT){
	printf("%d\n",bs[X][Y]);
      }else{
	int ans=0;
	for(int i=Y;i<N;i+=X){
	  ans+=as[i];
	}
	printf("%d\n",ans);
      }
    }
  }
}