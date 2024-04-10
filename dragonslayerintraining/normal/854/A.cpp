#include <cstdio>

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int x=N/2;x>0;x--){
    if(gcd(x,N)==1){
      printf("%d %d\n",x,N-x);
      return 0;
    }
  }
  return 0;
}