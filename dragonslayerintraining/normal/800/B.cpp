#include <iostream>
#include <stdint.h>
#include <cmath>
#include <iomanip>

int64_t N;

struct cpoint{
  int64_t x,y;
  cpoint(int64_t x,int64_t y):x(x),y(y){
  }
  cpoint():x(0),y(0){
  }
}points[1000];


struct cpoint operator-(struct cpoint a,struct cpoint b){
  return cpoint(a.x-b.x,a.y-b.y);
}

int64_t magn2(struct cpoint a){
  return a.x*a.x+a.y*a.y;
}

int64_t dist2(struct cpoint a,struct cpoint b){
  return magn2(a-b);
}

double dist(struct cpoint a,struct cpoint b){
  return sqrt(dist2(a,b));
}

double area(struct cpoint a,struct cpoint b,struct cpoint c){
  a=a-c;
  b=b-c;
  return double(a.y*b.x-a.x*b.y)/2;
}

double D=1e9;

void test(struct cpoint a,struct cpoint b,struct cpoint c){
  D=std::min(D,dist(a,c)/2);
  D=std::min(D,area(a,b,c)/dist(a,c));
}

int main(){
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    std::cin>>points[i].x>>points[i].y;
  }
  for(int64_t i=0;i<N;i++){
    test(points[i],points[(i+1)%N],points[(i+2)%N]);
  }
  std::cout<<std::fixed<<std::setprecision(10)<<D<<std::endl;
  return 0;
}