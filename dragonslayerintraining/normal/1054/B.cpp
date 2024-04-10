#include <cstdio>

int main(){
  int N;
  scanf("%d",&N);
  int mex=0;
  for(int i=1;i<=N;i++){
    int A;
    scanf("%d",&A);
    if(A>mex){
      printf("%d\n",i);
      return 0;
    }else if(A==mex){
      mex++;
    }
  }
  printf("-1\n");
  return 0;
}