#include <cstdio>

const int BLK=400;

int as[100000];
int small[BLK][100000];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int k=1;k<BLK;k++){
    for(int i=N-1;i>=0;i--){
      int j=i+as[i]+k;
      small[k][i]=(j<N)?(small[k][j]+1):1;
    }
  }
  int Q;
  scanf("%d",&Q);
  while(Q-->0){
    int P,K;
    scanf("%d %d",&P,&K);
    P--;
    if(K<BLK){
      printf("%d\n",small[K][P]);
    }else{
      int cnt=0;
      while(P<N){
	P=P+as[P]+K;
	cnt++;
      }
      printf("%d\n",cnt);
    }
  }
  return 0;
}