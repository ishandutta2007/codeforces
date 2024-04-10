#include <cstdio>
#include <cstdlib>

void fail(){
  printf("NO\n");
  exit(0);
}

void success(int x,int y){
  printf("YES\n");
  printf("0 0\n");
  printf("%d 0\n",x);
  printf("0 %d\n",y);
  exit(0);
}

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int main(){
  int N,M,K;
  scanf("%d %d %d",&N,&M,&K);
  if(K&1){
    int k1=gcd(K,N);
    int k2=K/k1;
    if(M%k2) fail();
    if(k1>1){
      success(N/k1*2,M/k2);
    }else{
      success(N/k1,M/k2*2);
    }
  }else{
    K/=2;
    int k1=gcd(K,N);
    int k2=K/k1;
    if(M%k2) fail();
    success(N/k1,M/k2);
  }
  return 0;
}