#include <cstdio>

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  int g=K;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    g=gcd(g,A);
  }
  printf("%d\n",K/g);
  for(int i=0;i<K;i+=g){
    if(i) printf(" ");
    printf("%d",i);
  }
  printf("\n");
  return 0;
}