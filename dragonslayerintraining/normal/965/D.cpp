#include <cstdio>
#include <algorithm>

int prefix[100001];

int main(){
  int W,L;
  scanf("%d %d",&W,&L);
  for(int i=1;i<W;i++){
    scanf("%d",&prefix[i]);
    prefix[i]+=prefix[i-1];
  }
  int best=1e9;
  for(int i=L;i<W;i++){
    best=std::min(best,prefix[i]-prefix[i-L]);
  }
  printf("%d\n",best);
  return 0;
}