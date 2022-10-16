#include <cstdio>
#include <algorithm>

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int as[100000];

int main(){
  int N;
  int G=0;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    G=gcd(G,as[i]);
  }
  if(std::count(as,as+N,G)){
    printf("%d\n",G);
  }else{
    printf("-1\n");
  }
  return 0;
}