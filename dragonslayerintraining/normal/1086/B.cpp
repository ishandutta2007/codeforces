#include <cstdio>

int deg[1000005];

int main(){
  int N,S;
  scanf("%d %d",&N,&S);
  if(N==2){
    printf("%d\n",S);
    return 0;
  }
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    deg[A]++,deg[B]++;
  }
  int leaves=0;
  for(int i=0;i<N;i++){
    if(deg[i]==1){
      leaves++;
    }
  }
  printf("%.10lf\n",(double)S*2/leaves);
  return 0;
}