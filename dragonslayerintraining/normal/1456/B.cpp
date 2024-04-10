#include <cstdio>

int as[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N-2;i++){
    if(as[i]>(as[i+1]^as[i+2])){
      printf("%d\n",1);
      return 0;
    }
  }
  for(int l=2;l<=N;l++){
    for(int a=1;a<l;a++){
      int b=l-a;
      for(int i=0;i+a+b<=N;i++){
	int asum=0;
	int bsum=0;
	for(int k=0;k<a;k++){
	  asum^=as[i+k];
	}
	for(int k=0;k<b;k++){
	  bsum^=as[i+a+k];
	}
	if(asum>bsum){
	  printf("%d\n",l-2);
	  return 0;
	}
      }
    }
  }
  printf("-1\n");
}