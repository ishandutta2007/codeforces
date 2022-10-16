#include <cstdio>

int as[1005];
int bs[1005];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&bs[i]);
  }
  for(int i=0;i<N;i++){
    if(as[i]==1||bs[i]==1){
      printf("-1\n");
      return 0;
    }
  }
  double ans=M;
  for(int i=N-1;i>=0;i--){
    ans+=ans/(bs[(i+1)%N]-1);
    ans+=ans/(as[i]-1);
  }
  printf("%.10lf\n",ans-M);
  return 0;
}