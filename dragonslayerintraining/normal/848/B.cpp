#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

typedef struct Point{
  int x,y;
  Point(){
  }
  Point(int x,int y):x(x),y(y){
  }
  bool operator<(struct Point other)const{
    return x-y<other.x-other.y;
  }
}Point;

std::map<int,std::pair<std::vector<std::pair<Point,int>>,std::vector<Point>>> vs;

Point ans[100000];

int main(){
  int N,W,H;
  scanf("%d %d %d",&N,&W,&H);
  for(int i=0;i<N;i++){
    int G,P,T;
    scanf("%d %d %d",&G,&P,&T);
    struct Point start,stop;
    if(G==2){
      start=Point(-T,P);
      stop=Point(W,P);
    }else{
      start=Point(P,-T);
      stop=Point(P,H);
    }
    vs[start.x+start.y].first.emplace_back(start,i);
    vs[start.x+start.y].second.push_back(stop);
  }
  for(auto group:vs){
    std::vector<std::pair<Point,int>>& start=group.second.first;
    std::vector<Point>& stop=group.second.second;
    std::sort(start.begin(),start.end());
    std::sort(stop.begin(),stop.end());
    for(int i=0;i<start.size();i++){
      ans[start[i].second]=stop[i];
    }
  }
  for(int i=0;i<N;i++){
    printf("%d %d\n",ans[i].x,ans[i].y);
  }
  return 0;
}