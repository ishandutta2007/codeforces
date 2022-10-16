#include <cstdio>

int N,K;

int len=0;

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    len+=R-L+1;
  }
  printf("%d\n",(K-len%K)%K);
  return 0;
}