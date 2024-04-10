#include <cstdio>
#include <stdint.h>

int vs[1<<18];

int main(){
  int N,R;
  scanf("%d %d",&N,&R);
  int64_t sum=0;
  for(int i=0;i<(1<<N);i++){
    scanf("%d",&vs[i]);
    sum+=vs[i];
  }
  printf("%.10f\n",(double)sum/(1<<N));
  for(int i=0;i<R;i++){
    int Z,G;
    scanf("%d %d",&Z,&G);
    sum-=vs[Z];
    vs[Z]=G;
    sum+=vs[Z];
    printf("%.10f\n",(double)sum/(1<<N));
  }
  return 0;
}