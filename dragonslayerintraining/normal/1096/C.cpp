#include <cstdio>

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int solve(int ang){
  int g=gcd(ang,180);
  int num=ang/g,den=180/g;
  if(den-num==1) return den*2;
  return den;
}

int main(){
  int T;
  scanf("%d",&T);
  while(T-->0){
    int ang;
    scanf("%d",&ang);
    printf("%d\n",solve(ang));
  }
  return 0;
}