#include <cstdio>
#include <map>

int main(){
  int N;
  scanf("%d",&N);
  std::map<int,std::pair<int,int>> map;
  std::pair<int,std::pair<int,int> > best{0,{0,1}};
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    map[A]=std::make_pair(0,i);
  }
  for(int k=30;k>=0;k--){
    while(map.rbegin()->first*2>(1<<k)){
      int a=map.rbegin()->first;
      int depth=map.rbegin()->second.first;
      int id=map.rbegin()->second.second;
      map.erase(a);
      a=(1<<k)-a;
      if(map.count(a)){
	best=std::max(best,std::make_pair(map[a].first+depth+1,std::make_pair(map[a].second,id)));
	map[a]=std::max(map[a],std::make_pair(depth+1,id));
      }else{
	map[a]=std::make_pair(depth+1,id);
      }
    }
  }
  printf("%d %d %d\n",best.second.first+1,best.second.second+1,best.first);
}