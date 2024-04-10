#include <cstdio>

int main(){
  int N;
  scanf("%d",&N);
  int k=0;
  while((1<<k)<=N) k++;
  printf("%d\n",k);
  return 0;
}