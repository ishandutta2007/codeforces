#include <cstdio>
#include <algorithm>

int as[361];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    as[i]+=as[i-1];
  }
  int i=0,j=0;
  int best=360;
  while((i<=N)||(j<=N)){
    int piece=as[i]-as[j];
    int diff=std::abs(piece-(360-piece));
    best=std::min(best,diff);
    if((i<=N)&&(as[i]-as[j]<180)){
      i++;
    }else{
      j++;
    }
  }
  printf("%d\n",best);
  return 0;
}