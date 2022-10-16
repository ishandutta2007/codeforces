#include <cstdio>
#include <algorithm>

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int main(){
  int N,A,B,P,Q;
  scanf("%d %d %d %d %d",&N,&A,&B,&P,&Q);
  printf("%lld\n",1LL*N/A*P+1LL*N/B*Q-N/(1LL*A*B/gcd(A,B))*std::min(P,Q));
}