#include <cstdio>
#include <algorithm>

std::pair<int,int> as[200005];
int ans[200005];

int main(){
  int N,M,D;
  scanf("%d %d %d",&N,&M,&D);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i].first);
    as[i].second=i;
  }
  std::sort(as,as+N);
  int low=0,high=N;
  while(high-low>1){
    int mid=(low+high)/2;
    int diff=1e9+7;
    for(int i=mid;i<N;i++){
      diff=std::min(diff,as[i].first-as[i-mid].first);
    }
    if(diff>D){
      high=mid;
    }else{
      low=mid;
    }
  }
  printf("%d\n",high);
  for(int i=0;i<N;i++){
    ans[as[i].second]=i%high+1;
  }
  for(int i=0;i<N;i++){
    if(i) printf(" ");
    printf("%d",ans[i]);
  }
  printf("\n");
  return 0;
}