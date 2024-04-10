#include <cstdio>
#include <algorithm>

int as[200005];
std::pair<int,int> bs[200005];
int ans[200005];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as,as+N);
  for(int i=0;i<M;i++){
    scanf("%d",&bs[i].first);
    bs[i].second=i;
  }
  std::sort(bs,bs+M);
  int i=0;
  for(int j=0;j<M;j++){
    while(i<N&&as[i]<=bs[j].first){
      i++;
    }
    ans[bs[j].second]=i;
  }
  for(int i=0;i<M;i++){
    if(i) printf(" ");
    printf("%d",ans[i]);
  }
  printf("\n");
  return 0;
}