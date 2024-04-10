#include <cstdio>
#include <algorithm>

int fs[100005];
int gs[100005];
int hs[100005];
int M=0;

int main(){
  int N;
  scanf("%d",&N);
  std::fill(gs,gs+N,-1);
  for(int i=0;i<N;i++){
    scanf("%d",&fs[i]);
    fs[i]--;
    if(i==fs[i]){
      gs[i]=M;
      hs[M]=i;
      M++;
    }
  }
  for(int i=0;i<N;i++){
    if(gs[fs[i]]==-1||hs[gs[fs[i]]]!=fs[i]){
      printf("-1\n");
      return 0;
    }
    gs[i]=gs[fs[i]];
  }
  printf("%d\n",M);
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",gs[i]+1);
  }
  printf("\n");
  for(int i=0;i<M;i++){
    if(i) printf(" ");
    printf("%d",hs[i]+1);
  }
  printf("\n");
  return 0;
}