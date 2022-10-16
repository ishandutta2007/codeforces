#include <cstdio>
#include <algorithm>

const int INF=1e9+7;

int cnt[5005];
int min[5005];
int N;

int dist(int i,int j){
  return (j-i+N)%N;
}

int main(){
  int M;
  scanf("%d %d",&N,&M);
  std::fill(min,min+N,INF);
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    cnt[A]++;
    min[A]=std::min(min[A],dist(A,B));
  }
  for(int i=0;i<N;i++){
    int ans=0;
    for(int j=0;j<N;j++){
      if(cnt[j]){
	ans=std::max(ans,dist(i,j)+(cnt[j]-1)*N+min[j]);
      }
    }
    if(i) printf(" ");
    printf("%d",ans);
  }
  printf("\n");
  return 0;
}