#include <cstdio>

int read(){
  int X;
  scanf("%d",&X);
  return X==1?1e9+7:(X==2?4:X);
}

int main(){
  int X=read(),Y=read();
  if(X>Y) printf("<\n");
  else if(X<Y) printf(">\n");
  else printf("=\n");
  return 0;
}