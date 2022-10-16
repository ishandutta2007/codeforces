#include <cstdio>
#include <algorithm>

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int X,Y;
    scanf("%d %d",&X,&Y);
    printf("%d\n",std::max(X,Y)*2-(X!=Y));
  }
}