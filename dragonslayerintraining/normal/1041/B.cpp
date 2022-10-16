#include <cstdio>
#include <algorithm>

int64_t gcd(int64_t a,int64_t b){
  return b?gcd(b,a%b):a;
}

int main(){
  int64_t A,B,X,Y;
  scanf("%I64d %I64d %I64d %I64d",&A,&B,&X,&Y);
  int64_t g=gcd(X,Y);
  X/=g,Y/=g;
  printf("%I64d\n",std::min(A/X,B/Y));
  return 0;
}