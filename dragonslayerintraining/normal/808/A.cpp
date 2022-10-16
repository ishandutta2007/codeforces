#include <cstdio>

int main(){
  int N;
  scanf("%d",&N);
  int scale=1;
  while(N/scale>=10) scale*=10;
  printf("%d\n",(N/scale+1)*scale-N);
  return 0;
}