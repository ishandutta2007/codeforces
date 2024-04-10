#include <cstdio>
#include <cassert>
#include <cmath>
#include <map>
#include <chrono>
#include <random>
#include <algorithm>

const double TAU=8*atan(1);
const double eps=1e-9;

struct Point{
  double x,y;
  Point():x(0),y(0){}
  Point(double x,double y):x(x),y(y){}
  struct Point operator+(struct Point p)const{return Point(x+p.x,y+p.y);}
  struct Point operator-(struct Point p)const{return Point(x-p.x,y-p.y);}
  double operator*(struct Point p)const{return x*p.x+y*p.y;}
  double operator^(struct Point p)const{return x*p.y-y*p.x;}
  double norm(){return std::hypot(x,y);}
  double arg(){return std::atan2(y,x);}
  void read(){
    scanf("%lf %lf",&x,&y);
  }
}points[1000];
int W,H,N;
  
void add_range(std::map<double,int>& delta,double center,double pm,int x){
  assert(pm==pm);
  assert(pm>=0);
  //printf("Range %.10lf+/-%.10lf\n",center/TAU,pm/TAU);
  double l=center-pm,r=center+pm;
  if(l<0) l+=TAU,r+=TAU;
  delta[l]+=x,delta[r]-=x;
  delta[l+TAU]+=x,delta[r+TAU]-=x;
}

void add_wall(std::map<double,int>& delta,double center,double dist,double radius){
  if(dist/radius<=1){
    add_range(delta,center,std::acos(dist/radius),2);
  }
}

bool check(int index,double radius){
  //printf("check(%d,R=%.10lf)\n",index,radius);
  std::map<double,int> delta;
  for(int i=0;i<N;i++){
    struct Point diff=points[i]-points[index];
    if(diff.norm()/2/radius<=1&&diff.norm()>0){
      add_range(delta,diff.arg(),std::acos(diff.norm()/2/radius),1);
    }
  }
  add_wall(delta,0,W-points[index].x,radius);
  add_wall(delta,TAU/4,H-points[index].y,radius);
  add_wall(delta,TAU/2,points[index].x,radius);
  add_wall(delta,3*TAU/4,points[index].y,radius);
  int cnt=0;
  delta[TAU];
  for(auto it:delta){
    cnt+=it.second;
    assert(cnt>=0);
    //printf("event: t=%.10lf, delta=%d\n",it.first/TAU,it.second);
    if(it.first>=TAU&&it.first<=TAU*2&&cnt<=1){
      return true;
    }
  }
  return false;
}

int main(){
  scanf("%d %d %d",&W,&H,&N);
  for(int i=0;i<N;i++){
    points[i].read();
  }
  double low=0.5;
  std::vector<int> is(N);
  std::iota(is.begin(),is.end(),0);
  std::mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
  std::shuffle(is.begin(),is.end(),rng);
  for(int i:is){
    if(!check(i,low+eps)) continue;
    double high=2e6;
    while(high-low>1e-9){
      double mid=(low+high)/2;
      if(check(i,mid)){
	low=mid;
      }else{
	high=mid;
      }
    }
  }
  printf("%.10lf\n",low);
  return 0;
}