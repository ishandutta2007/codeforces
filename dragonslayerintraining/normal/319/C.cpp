#include <iostream>
#include <vector>
#include <stdint.h>

int64_t N;

int64_t as[100000];
int64_t bs[100000];

std::vector<std::pair<int64_t,int64_t> > slopes;//(slope,int64_tercept)
std::vector<int64_t> xs;

int64_t query(int64_t x){
  int64_t low=0,high=xs.size();
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(xs[mid]<=x){
      low=mid;
    }else{
      high=mid;
    }
  }
  return slopes[low].first*x+slopes[low].second;
}

void insert(int64_t m,int64_t b){
  while(true){
    int64_t num=b-slopes.back().second;
    int64_t den=slopes.back().first-m;
    int64_t x=(num+den-1)/den;
    if(x>xs.back()){
      slopes.emplace_back(m,b);
      xs.push_back(x);
      return;
    }
    xs.pop_back();
    slopes.pop_back();
  }
}

int main(){
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
  }
  for(int64_t i=0;i<N;i++){
    std::cin>>bs[i];
  }
  slopes.emplace_back(bs[0],0);
  xs.push_back(0);
  int64_t dp;
  for(int64_t i=1;i<N;i++){
    dp=query(as[i]);
    insert(bs[i],dp);
  }
  std::cout<<dp<<std::endl;
  return 0;
}