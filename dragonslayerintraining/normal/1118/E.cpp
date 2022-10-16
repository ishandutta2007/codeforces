#include <cstdio>

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  if(N>1LL*K*(K-1)){
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  for(int l=0;l<K*2;l++){
    for(int i=0;i<=l;i++){
      int j=l-i;
      if(i>=K||j>=K) continue;
      if(i==j) continue;
      printf("%d %d\n",i+1,j+1);
      if(--N==0) return 0;
    }
  }
  return 0;
}