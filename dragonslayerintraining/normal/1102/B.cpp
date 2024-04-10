#include <cstdio>

bool has[5005][5005];
int cs[5005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    int X;
    scanf("%d",&X);
    if(i<K){
      cs[i]=i;
    }else{
      while(has[cs[i]][X]){
	cs[i]++;
      }
    }
    if(cs[i]>=K){
      printf("NO\n");
      return 0;
    }
    has[cs[i]][X]=true;
  }
  printf("YES\n");
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",cs[i]+1);
  }
  printf("\n");
  return 0;
}