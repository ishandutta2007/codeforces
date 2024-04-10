#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point{
  int x,y;
}ps[3];

struct XCmp{
  bool operator()(struct Point a,struct Point b)const{
    return a.x<b.x;
  }
};
struct YCmp{
  bool operator()(struct Point a,struct Point b)const{
    return a.y<b.y;
  }
};

int main(){
  for(int i=0;i<3;i++){
    scanf("%d %d",&ps[i].x,&ps[i].y);
  }
  std::sort(ps,ps+3,XCmp());
  std::vector<struct Point> vs;
  while(ps[0].x<ps[1].x){
    vs.push_back(ps[0]);
    ps[0].x++;
  }
  while(ps[2].x>ps[1].x){
    vs.push_back(ps[2]);
    ps[2].x--;
  }
  std::sort(ps,ps+3,YCmp());
  while(ps[0].y<ps[1].y){
    vs.push_back(ps[0]);
    ps[0].y++;
  }
  while(ps[2].y>ps[1].y){
    vs.push_back(ps[2]);
    ps[2].y--;
  }
  vs.push_back(ps[0]);
  printf("%d\n",(int)vs.size());
  for(struct Point p:vs){
    printf("%d %d\n",p.x,p.y);
  }
  return 0;
}