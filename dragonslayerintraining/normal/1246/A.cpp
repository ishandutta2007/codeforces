#include <cstdio>

int main(){
  int N,P;
  scanf("%d %d",&N,&P);
  for(int pop=1;pop<1000000;pop++){
    long long x=N-1LL*P*pop;
    //can x be written as the sum of $pop powers of 2
    if(x>=pop&&__builtin_popcountll(x)<=pop){
      printf("%d\n",pop);
      return 0;
    }
  }
  printf("-1\n");
}