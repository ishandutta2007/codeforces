#include <cstdio>

long long ps[100005];

int main(){
  long long N,M,K;
  scanf("%I64d %I64d %I64d",&N,&M,&K);
  for(int i=0;i<M;i++){
    scanf("%I64d",&ps[i]);
    ps[i]--;
  }
  int first=0;
  int i=0;
  int cnt=0;
  while(i<M){
    while(i<M&&(ps[i]-first)/K==(ps[first]-first)/K){
      i++;
    }
    first=i;
    cnt++;
  }
  printf("%d\n",cnt);
}