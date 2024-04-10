#include <cstdio>

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int N;
    scanf("%d",&N);
    printf("%d\n",(2<<(N/2))-2);
  }
}