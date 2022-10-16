#include <cstdio>

int ss[1000];

int g=0;

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ss[i]);
    g=gcd(g,ss[i]);
  }
  if(g!=ss[0]){
    printf("-1\n");
  }else{
    printf("%d\n",N*2-1);
    for(int i=1;i<N;i++){
      printf("%d %d ",ss[0],ss[i]);
    }
    printf("%d\n",ss[0]);
  }
  return 0;
}