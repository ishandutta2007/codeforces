#include <cstdio>
#include <algorithm>

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int table[27];

int f(int x){
  for(int k=0;k<27;k++){
    if(x==((1<<k)-1)){
      return table[k];
    }
  }
  int k=0;
  while((1<<k)<=x) k++;
  return (1<<k)-1;
}

/*
int g(int x){
  int best=0;
  for(int y=1;y<x;y++){
    best=std::max(best,gcd(x^y,x&y));
  }
  return best;
}
*/

int main(){
  table[1]=0;
  for(int k=2;k<27;k++){
    int x=(1<<k)-1;
    table[k]=1;
    for(int i=2;i*i<=x;i++){
      if(x%i==0){
	table[k]=x/i;
	break;
      }
    }
  }
  /*
  for(int i=1;i<=10000;i++){
    if(f(i)!=g(i)){
      printf("%d: %d %d\n",i,f(i),g(i));
    }
  }
  */
  int Q;
  scanf("%d",&Q);
  while(Q-->0){
    int A;
    scanf("%d",&A);
    printf("%d\n",f(A));
  }
  return 0;
}