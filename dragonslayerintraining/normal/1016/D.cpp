#include <cstdio>
#include <cassert>

int as[200];
int bs[200];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  int sum=0;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    sum^=as[i];
  }
  for(int i=0;i<M;i++){
    scanf("%d",&bs[i]);
    sum^=bs[i];
  }
  if(sum!=0){
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  for(int i=0;i<N-1;i++){
    for(int j=0;j<M-1;j++){
      printf("0 ");
    }
    printf("%d\n",as[i]);
  }
  assert(sum==0);
  for(int j=0;j<M-1;j++){
    printf("%d ",bs[j]);
    sum^=bs[j];
  }
  printf("%d\n",sum^as[N-1]);
  return 0;
}