#include <cstdio>
#include <algorithm>
#include <vector>

struct Point{
  double x,y;
  Point():x(0),y(0){
  }
  Point(double x,double y):x(x),y(y){
  }
  void read(){
    scanf("%lf %lf",&x,&y);
  }
  double manhattan(struct Point p)const{
    return std::abs(x-p.x)+std::abs(y-p.y);
  }
  double euclidean(struct Point p)const{
    return std::hypot(x-p.x,y-p.y);
  }
}start,end;

std::vector<struct Point> mid[2];

int main(){
  int A,B,C;
  scanf("%d %d %d",&A,&B,&C);
  start.read(),end.read();
  double ans=start.manhattan(end);
  if(B) mid[0].push_back({start.x,(-C-A*start.x)/B});
  if(A) mid[0].push_back({(-C-B*start.y)/A,start.y});
  if(B) mid[1].push_back({end.x,(-C-A*end.x)/B});
  if(A) mid[1].push_back({(-C-B*end.y)/A,end.y});
  for(struct Point m1:mid[0]){
    for(struct Point m2:mid[1]){
      //printf("(%lf,%lf) (%lf,%lf)\n",m1.x,m1.y,m2.x,m2.y);
      ans=std::min<double>(ans,start.manhattan(m1)+m1.euclidean(m2)+m2.manhattan(end));
    }
  }
  printf("%.10lf\n",ans);
  return 0;
}