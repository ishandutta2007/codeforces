#include <cstdio>
#include <vector>
#include <algorithm>

struct Point{
  long long x,y;
  Point operator-(Point p)const{
    return Point{x-p.x,y-p.y};
  }
  bool operator<(Point p)const{
    if(x!=p.x) return x<p.x;
    return y>p.y;
  }
  long long cross(Point p)const{
    return x*p.y-y*p.x;
  }
}ps[100005];

bool ccw(Point a,Point b,Point c){
  return (b-a).cross(c-a)>=0;
}

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%lld %lld",&ps[i].x,&ps[i].y);
    ps[i].y-=ps[i].x*ps[i].x;
  }
  std::sort(ps,ps+N);
  std::vector<Point> hull;
  for(int i=0;i<N;i++){
    while(hull.size()>=2&&ccw(hull[hull.size()-2],hull[hull.size()-1],ps[i])){
      hull.pop_back();
    }
    hull.push_back(ps[i]);
  }
  while(hull.size()>1&&hull[hull.size()-2].x==hull[hull.size()-1].x){
    hull.pop_back();
  }
  printf("%d\n",(int)hull.size()-1);
}