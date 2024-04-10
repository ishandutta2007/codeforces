#include <cstdio>

int main(){
  int K,N,S,P;
  scanf("%d %d %d %d",&K,&N,&S,&P);
  printf("%d\n",((N+S-1)/S*K+P-1)/P);
  return 0;
}