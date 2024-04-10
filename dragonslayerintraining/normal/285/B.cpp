#include <cstdio>

int ps[100000];
int N,S,T;

int main(){
  scanf("%d %d %d",&N,&S,&T);
  S--,T--;
  for(int i=0;i<N;i++){
    scanf("%d",&ps[i]);
    ps[i]--;
  }
  for(int i=0;i<N;i++){
    if(S==T){
      printf("%d\n",i);
      return 0;
    }
    S=ps[S];
  }
  printf("-1\n");
  return 0;
}