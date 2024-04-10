#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <stdint.h>

struct Point{
  int x,y;
  Point(int x,int y):x(x),y(y){
  }
};

struct XCmp{
  bool operator()(struct Point a,struct Point b)const{
    if(a.x!=b.x){
      return a.x<b.x;
    }
    return a.y<b.y;
  }
};

struct YCmp{
  bool operator()(struct Point a,struct Point b)const{
    if(a.y!=b.y){
      return a.y<b.y;
    }
    return a.x<b.x;
  }
};

int64_t cnt=0;

void solve(std::vector<struct Point> points){
  if(points.empty()) return;
  std::set<struct Point,struct YCmp> before,after;
  std::map<int,std::vector<struct Point> > layers;
  for(struct Point p:points){
    layers[p.x].push_back(p);
    before.insert(p);
  }
  for(int x=layers.begin()->first;x<layers.rbegin()->first;x+=2){
    for(struct Point p:layers[x]){
      before.erase(p);
      after.insert(p);
    }
    int low=std::max(before.begin()->y,after.begin()->y);
    int high=std::min(before.rbegin()->y,after.rbegin()->y);
    if(high>low){
      cnt+=(high-low)/2;
    }
  }
}

int main(){
  int N;
  std::cin>>N;
  std::vector<struct Point> even,odd;
  for(int i=0;i<N;i++){
    int X,Y;
    std::cin>>X>>Y;
    if((X+Y)%2){
      odd.emplace_back(X+Y,X-Y);
    }else{
      even.emplace_back(X+Y,X-Y);
    }
  }
  solve(even);
  solve(odd);
  std::cout<<cnt<<std::endl;
  return 0;
}