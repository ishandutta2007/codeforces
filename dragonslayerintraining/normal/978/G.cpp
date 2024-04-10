#include <cstdio>
#include <vector>
#include <tuple>
#include <set>

std::vector<std::tuple<int,int,int> > add[101];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int S,D,C;
    scanf("%d %d %d",&S,&D,&C);
    add[S].emplace_back(D,C,i+1);
    add[D].emplace_back(D,1,M+1);
  }
  std::vector<int> days;
  std::multiset<std::tuple<int,int,int> > active;
  for(int i=1;i<=N;i++){
    active.insert(add[i].begin(),add[i].end());
    if(active.empty()){
      days.push_back(0);
      continue;
    }
    int end=std::get<0>(*active.begin());
    int cnt=std::get<1>(*active.begin());
    int id=std::get<2>(*active.begin());
    active.erase(active.begin());
    
    if(end<i){
      printf("-1\n");
      return 0;
    }
    
    if(cnt>1){
      active.emplace(end,cnt-1,id);
    }
    days.push_back(id);
  }
  if(!active.empty()){
    printf("-1\n");
    return 0;
  }
  for(int i=0;i<days.size();i++){
    if(i) printf(" ");
    printf("%d",days[i]);
  }
  printf("\n");
  return 0;
}