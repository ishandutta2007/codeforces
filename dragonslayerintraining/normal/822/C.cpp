#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <stdint.h>

struct endpoint{
  int loc;
  enum etype{
    ENDPOINT_BEGIN=0,
    ENDPOINT_END=1,
  }type;
  int duration;
  int64_t cost;
  endpoint(int loc,enum etype type,int duration,int64_t cost):loc(loc),type(type),duration(duration),cost(cost){
  }
  bool operator<(struct endpoint other)const{
    if(loc!=other.loc){
      return loc<other.loc;
    }
    if(type!=other.type){
      return type<other.type;
    }
    return false;
  }
};

std::vector<struct endpoint> ends;
std::map<int,int64_t> mins;

int main(){
  int N,X;
  scanf("%d %d",&N,&X);
  for(int i=0;i<N;i++){
    int L,R,cost;
    scanf("%d %d %d",&L,&R,&cost);
    int duration=R-L+1;
    if(duration<=X){
      ends.emplace_back(L,endpoint::ENDPOINT_BEGIN,duration,cost);
      ends.emplace_back(R,endpoint::ENDPOINT_END,duration,cost);
    }
  }
  std::sort(ends.begin(),ends.end());
  int64_t best=1e10;
  for(struct endpoint end:ends){
    switch(end.type){
    case endpoint::ENDPOINT_BEGIN:
      if(mins.count(end.duration)){
	best=std::min<int64_t>(best,mins[end.duration]+end.cost);
      }
      break;
    case endpoint::ENDPOINT_END:
      if(!mins.count(X-end.duration)){
	mins[X-end.duration]=end.cost;
      }else{
	mins[X-end.duration]=std::min<int64_t>(mins[X-end.duration],end.cost);
      }
      break;
    }
  }
  printf("%ld\n",(best<1e10)?best:-1);
  return 0;
}