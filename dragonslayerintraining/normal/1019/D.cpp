#include <cstdio>
#include <algorithm>
#include <vector>
#include <stdint.h>
#include <cstdlib>
#include <tuple>
#include <cassert>

struct Point{
  int64_t x,y;
  Point(){
  }
  Point(int64_t x,int64_t y):x(x),y(y){
  }
}points[2005];
int where[2005];
int N;

struct Point operator-(struct Point a,struct Point b){
  return Point(a.x-b.x,a.y-b.y);
}

int64_t cross(struct Point a,struct Point b){
  return a.x*b.y-a.y*b.x;
}

int64_t area(struct Point a,struct Point b,struct Point c){
  return cross(b-a,c-a);
}

struct PointPair{
  struct Point diff;
  int i1,i2;
  PointPair(struct Point diff,int i1,int i2):diff(diff),i1(i1),i2(i2){
  }
};

struct AngleCmp{
  bool operator()(struct PointPair p1,struct PointPair p2){
    return cross(p1.diff,p2.diff)>0;
  }
};

struct YCmp{
  bool operator()(struct Point a,struct Point b){
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
  }
};

void answer(struct Point a,struct Point b,struct Point c){
  printf("Yes\n");
  printf("%I64d %I64d\n",a.x,a.y);
  printf("%I64d %I64d\n",b.x,b.y);
  printf("%I64d %I64d\n",c.x,c.y);
  exit(0);
}

void search(struct Point p1,struct Point p2,int64_t S){
  //search for S
  int low=0,high=N;
  while(high-low>1){
    int mid=(low+high)/2;
    int64_t a=area(p1,p2,points[mid]);//twice signed area
    if(a<S){
      low=mid;
    }else if(a>S){
      high=mid;
    }else{
      answer(p1,p2,points[mid]);//exits
    }
  }
}
  
int main(){
  int64_t S;
  scanf("%d %I64d",&N,&S);
  S*=2;
  for(int i=0;i<N;i++){
    scanf("%I64d %I64d",&points[i].x,&points[i].y);
  }
  std::iota(where,where+N,0);
  std::sort(points,points+N,YCmp());
  std::vector<struct PointPair> pairs;
  for(int j=0;j<N;j++){
    for(int i=0;i<j;i++){
      pairs.emplace_back(points[j]-points[i],i,j);
    }
  }
  std::sort(pairs.begin(),pairs.end(),AngleCmp());
  for(auto pair:pairs){
    struct Point& p1=points[where[pair.i1]];
    struct Point& p2=points[where[pair.i2]];

    search(p1,p2,S);
    search(p1,p2,-S);
    
    std::swap(p1,p2);
    std::swap(where[pair.i1],where[pair.i2]);
  }
  printf("No\n");
  return 0;
}