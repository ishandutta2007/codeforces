#include <cstdio>
#include <algorithm>
#include <functional>
#include <map>

const int INF=1e9+7;

int as[300005];

int last[300005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  std::copy(as,as+N,as+N);
  std::map<int,int,std::greater<int> > map;//as[i] => (first pos <= as[i]/2)
  map[0]=INF;
  for(int i=N*2-1;i>=0;i--){
    while(map.begin()->first>as[i]*2){
      map.erase(map.begin());
    }
    map[as[i]*2]=i;
    last[i]=map.upper_bound(as[i])->second;
  }
  for(int i=0;i<N;i++){
    last[i+N]=last[i]+N;
  }
  for(int i=N*2-2;i>=0;i--){
    last[i]=std::min(last[i],last[i+1]);
  }
  if(last[0]>N*3){
    for(int i=0;i<N;i++){
      printf("-1 ");
    }
  }else{
    for(int i=0;i<N;i++){
      printf("%d ",last[i]-i);
    }
  }
  printf("\n");
}