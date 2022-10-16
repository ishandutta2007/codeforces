#include <cstdio>
#include <algorithm>

int ts[1000];

int main(){
  int N,A,B,C,T;
  scanf("%d %d %d %d %d",&N,&A,&B,&C,&T);
  for(int i=0;i<N;i++){
    scanf("%d",&ts[i]);
  }
  int ans=0;
  for(int i=0;i<N;i++){
    ans+=A+std::max(0,(C-B)*(T-ts[i]));
  }
  printf("%d\n",ans);
  return 0;
}