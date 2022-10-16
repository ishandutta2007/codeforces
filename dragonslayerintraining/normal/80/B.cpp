#include <cstdio>

int main(){
  int H,M;
  scanf("%d:%d",&H,&M);
  H%=12;
  printf("%lf %d\n",((H+double(M)/60)*30),M*6);
  return 0;
}