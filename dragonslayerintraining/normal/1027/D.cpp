#include <cstdio>
#include <algorithm>

int cs[200005];
int as[200005];

bool vis[200005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&cs[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    as[i]--;
  }
  int cost=0;
  for(int i=0;i<N;i++){
    int slow=as[i],fast=as[as[i]];
    while(fast!=slow){
      if(vis[fast]||vis[slow]) break;
      fast=as[as[fast]];
      slow=as[slow];
    }
    if(vis[fast]){
      for(int j=i;j!=fast;j=as[j]){
	vis[j]=true;
      }
      continue;
    }
    int cheap=1e9;
    do{
      cheap=std::min(cheap,cs[fast]);
      vis[fast]=true;
      fast=as[fast];
    }while(fast!=slow);
    cost+=cheap;
    for(int j=i;j!=fast;j=as[j]){
      vis[j]=true;
    }
  }
  printf("%d\n",cost);
  return 0;
}