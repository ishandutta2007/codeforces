#include <cstdio>
#include <algorithm>

int increase[100005];
int N;

int main(){
  scanf("%d",&N);
  int first=0,second=0;
  for(int i=1;i<=N;i++){
    int X;
    scanf("%d",&X);
    if(X>first){
      second=first;
      first=X;
      
      increase[X]--;
    }else if(X>second){
      second=X;

      increase[first]++;
    }
  }
  std::pair<int,int> best(-1e9,-1e9);
  for(int i=1;i<=N;i++){
    best=std::max(best,std::make_pair(increase[i],-i));
  }
  printf("%d\n",-best.second);
  return 0;
}