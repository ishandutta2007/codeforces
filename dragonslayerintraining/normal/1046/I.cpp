#include <cstdio>
#include <vector>
#include <cmath>

const double EPS=1e-7;

struct Point{
  double x,y;
  Point operator-(Point p)const{
    return Point{x-p.x,y-p.y};
  }
  Point operator*(double s)const{
    return Point{x*s,y*s};
  }
  double cross(Point p)const{
    return x*p.y-y*p.x;
  }
  double dot(Point p)const{
    return x*p.x+y*p.y;
  }
  double magn2()const{
    return x*x+y*y;
  }
  double magn()const{
    return std::hypot(x,y);
  }
  Point normal()const{
    return (*this)*(1.0/magn());
  }
};

//[a,b] and B(c,r)
bool intersect(Point a,Point b,Point c,double r){
  if((a-b).magn()<EPS){
    return (a-c).magn()<=r;
  }
  //line-circle distance
  double sep=std::abs((c-a).cross(c-b))/(a-b).magn();
  if(sep>r) return false;
  double delta=std::sqrt((r-sep)*(r+sep));
  double mid=(c-a).dot((b-a).normal());
  double low=mid-delta,high=mid+delta;
  return std::max(low,0.0)<=std::min(high,(b-a).magn())+EPS;
}


std::vector<Point> ps;

int main(){
  int N,D1,D2;
  scanf("%d %d %d",&N,&D1,&D2);
  for(int i=0;i<N;i++){
    int x0,y0,x1,y1;
    scanf("%d %d %d %d",&x0,&y0,&x1,&y1);
    ps.push_back({x1-x0,y1-y0});
  }
  bool away=true;
  int hello=0;
  for(int i=1;i<N;i++){
    if(away&&intersect(ps[i-1],ps[i],Point{0,0},D1)){
      away=false;
      hello++;
    }
    if(std::hypot(ps[i].x,ps[i].y)>D2){
      away=true;
    }
  }
  printf("%d\n",hello);
}