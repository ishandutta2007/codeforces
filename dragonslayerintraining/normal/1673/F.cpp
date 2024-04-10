#include <cstdio>

int N,K;

int id(int r,int c){
  r^=r>>1;
  c^=c>>1;
  int res=0;
  for(int k=0;k<5;k++){
    res|=((r>>k)&1)<<(k*2);
    res|=((c>>k)&1)<<(k*2+1);
  }
  return res;
}

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    for(int j=0;j<N-1;j++){
      if(j) printf(" ");
      printf("%d",id(i,j)^id(i,j+1));
    }
    printf("\n");
  }
  for(int i=0;i<N-1;i++){
    for(int j=0;j<N;j++){
      if(j) printf(" ");
      printf("%d",id(i,j)^id(i+1,j));
    }
    printf("\n");
  }
  fflush(stdout);
  int loc=0;
  while(K--){
    int X;
    scanf("%d",&X);
    loc^=X;
    for(int r=0;r<32;r++){
      for(int c=0;c<32;c++){
	if(id(r,c)==loc){
	  printf("%d %d\n",r+1,c+1);
	}
      }
    }
    fflush(stdout);
  }
}