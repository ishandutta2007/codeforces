#include <cstdio>
#include <algorithm>

int N,K;
int as[100001];

int num[100001];
int last[100001];

int main(){
  scanf("%d %d",&N,&K);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=1;i<=N;i++){
    int first=std::max(last[as[i]]+1,i-K);
    num[i]=num[as[i]]+std::min(N,i+K)-first+1;
    last[i]=std::min(N,i+K);
    if(i>1) printf(" ");
    printf("%d",num[i]);
  }
  printf("\n");
  return 0;
}