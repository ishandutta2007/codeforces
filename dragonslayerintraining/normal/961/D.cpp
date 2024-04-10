#include <cstdio>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stdint.h>

struct Point{
  int64_t x,y;
  Point():x(0),y(0){
  }
  Point(int64_t x,int64_t y):x(x),y(y){
  }
  bool operator==(struct Point other)const{
    return x==other.x&&y==other.y;
  }
  struct Point operator-(struct Point other)const{
    return Point(x-other.x,y-other.y);
  }
  int64_t cross(struct Point other)const{
    return x*other.y-y*other.x;
  }
}points[100000];

bool collinear(struct Point a,struct Point b,struct Point c){
  return (b-a).cross(c-a)==0;
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d %I64d",&points[i].x,&points[i].y);
  }
  if(N<=4){
    printf("YES\n");
    return 0;
  }
  for(int t=0;t<3;t++){
    struct Point p1=points[t];
    struct Point p2=points[(t+1)%3];
    std::vector<struct Point> bad;
    for(int64_t i=0;i<N;i++){
      if(!collinear(p1,p2,points[i])){
	bad.push_back(points[i]);
      }
    }
    if(bad.size()<=2){
      printf("YES\n");
      return 0;
    }
    bool good=true;
    for(int64_t i=2;i<bad.size();i++){
      if(!collinear(bad[0],bad[1],bad[i])){
	good=false;
      }
    }
    if(good){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}