#include <cstdio>
#include <vector>
#include <cassert>
#include <stdint.h>

int64_t TB,TS;

struct Point{
  int64_t x,y;
  Point(int64_t x,int64_t y):x(x),y(y){
  }
  struct Point operator-(struct Point p)const{
    return Point(x-p.x,y-p.y);
  }
  long double cross(struct Point p)const{
    return (long double)x*p.y-(long double)y*p.x;
  }
  int64_t eval(){
    return y+(long double)x*TS+TB;
  }
};

std::vector<struct Point> hull;
int64_t length=0;

void add(int64_t K){
  struct Point p(length,-TB-(long double)TS*length);
  while(hull.size()>=2&&(p-hull[hull.size()-2]).cross(hull.back()-hull[hull.size()-2])>0){
    hull.pop_back();
  }
  hull.push_back(p);
  length+=K;
}

void reduce(){
  while(hull.size()>1&&hull.back().eval()>=hull[hull.size()-2].eval()){
    hull.pop_back();
  }
}

int main(){
  hull.emplace_back(0,0);
  int64_t M;
  scanf("%I64d %I64d",&length,&M);
  while(M-->0){
    int64_t T;
    scanf("%I64d",&T);
    if(T==1){
      int64_t K;
      scanf("%I64d",&K);
      TB=TS=0;
      hull.clear();
      int64_t tmp=length;
      length-=tmp;
      add(K);
      length+=tmp;
    }else if(T==2){
      int64_t K;
      scanf("%I64d",&K);
      add(K);
    }else if(T==3){
      int64_t B,S;
      scanf("%I64d %I64d",&B,&S);
      TB+=B,TS+=S;
    }else{
      assert(0);
    }
    reduce();
    /*
    for(struct Point p:hull){
      printf("(%I64d, %I64d)\n",p.x,p.eval());
    }
    */
    printf("%I64d %I64d\n",hull.back().x+1,hull.back().eval());
  }
  return 0;
}