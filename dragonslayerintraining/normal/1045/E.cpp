#include <cstdio>
#include <stdint.h>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdlib>

//Helper functions
std::vector<std::pair<int,int> > edges;

void connect(int a,int b){
  //printf("connect(%d,%d)\n",a,b);
  edges.push_back({a,b});
}

void fail(){
  printf("Impossible\n");
  exit(0);
}

void output(){
  printf("%d\n",(int)edges.size());
  for(auto e:edges){
    printf("%d %d\n",e.first,e.second);
  }
  exit(0);
}

//End helper functions

struct Point{
  int x,y;
  Point():x(0),y(0){
  }
  void read(){
    scanf("%d %d",&x,&y);
  }
  Point(int x,int y):x(x),y(y){
  }
  struct Point operator-(struct Point p)const{
    return Point(x-p.x,y-p.y);
  }
  bool operator<(struct Point p)const{
    if(y!=p.y) return y<p.y;
    return x<p.x;
  }
  int64_t cross(struct Point p)const{
    return 1LL*x*p.y-1LL*y*p.x;
  }
}ps[1005];
int ts[1005];
int N;

bool ccw(struct Point a,struct Point b,struct Point c){
  return (b-a).cross(c-a)>0;
}

bool ccw(int a,int b,int c){
  return ccw(ps[a],ps[b],ps[c]);
}

bool inside(int a,int b,int c,int p){
  assert(ccw(a,b,c));
  return ccw(a,b,p)&&ccw(b,c,p)&&ccw(c,a,p);
}

std::vector<int> convexhull(){
  std::vector<int> order;
  std::vector<int> upper,lower;
  for(int i=0;i<N;i++){
    order.push_back(i);
  }
  std::sort(order.begin(),order.end(),[](int i,int j){return ps[i]<ps[j];});
  for(int i:order){
    while(upper.size()>=2&&!ccw(upper[upper.size()-2],upper[upper.size()-1],i)){
      upper.pop_back();
    }
    upper.push_back(i);
  }
  std::reverse(order.begin(),order.end());
  for(int i:order){
    while(lower.size()>=2&&!ccw(lower[lower.size()-2],lower[lower.size()-1],i)){
      lower.pop_back();
    }
    lower.push_back(i);
  }
  upper.pop_back();
  lower.pop_back();
  upper.insert(upper.end(),lower.begin(),lower.end());
  /*
  printf("Hull:\n");
  for(int i:upper){
    printf("(%d,%d)\n",ps[i].x,ps[i].y);
  }
  */
  return upper;
}

//a,b,c are indices of points
//a, b and c have the same type and are already connected
//ccw(a,b,c)>0
//connect all points on the interior of triangle abc to the a, b and c
void join1(int a,int b,int c){
  //printf("join1(%d,%d,%d)\n",a,b,c);
  assert(a!=b&&a!=c&&b!=c);
  assert(ts[a]==ts[b]&&ts[b]==ts[c]);
  assert(ccw(a,b,c)>0);
  for(int i=0;i<N;i++){
    if(inside(a,b,c,i)){
      assert(i!=a&&i!=b&&i!=c);//should fail ccw
      assert(ts[i]==ts[a]);
      connect(i,a);
      join1(i,a,b);
      join1(i,b,c);
      join1(i,c,a);
      return;
    }
  }
}

//a,b,c are indices of points
//b and c have the same type and are already connected
//a has the opposite type
//ccw(a,b,c)>0
//connect all points on the interior of triangle abc to the appropriate type
void join2(int a,int b,int c){
  //printf("join2(%d,%d,%d)\n",a,b,c);
  assert(a!=b&&a!=c&&b!=c);
  assert(ts[a]!=ts[b]&&ts[b]==ts[c]);
  assert(ccw(a,b,c)>0);
  for(int i=0;i<N;i++){
    if(ts[i]==ts[a]&&inside(a,b,c,i)){
      assert(i!=a&&i!=b&&i!=c);//should fail ccw
      connect(a,i);
      join2(c,a,i);
      join2(b,i,a);
      join2(i,b,c);
      return;
    }
  }
  //No points with same type as a inside triangle
  for(int i=0;i<N;i++){
    if(inside(a,b,c,i)){
      assert(i!=a&&i!=b&&i!=c);//should fail ccw
      assert(ts[i]!=ts[a]);
      connect(b,i);
      join2(a,i,c);
      join2(a,b,i);
      join1(i,b,c);
      return;
    }
  }
}

void solve(){
  std::vector<int> hull=convexhull();
  int flip=std::find_if(hull.begin(),hull.end(),[&hull](int i){return ts[i]!=ts[hull[0]];})-hull.begin();
  if(flip==hull.size()){
    //printf("Convex hull has one type\n");
    for(int i=1;i<hull.size();i++){
      connect(hull[i-1],hull[i]);
    }
    for(int i=0;i<N;i++){
      if(ts[i]!=ts[hull[0]]){
	for(int j=0;j<hull.size();j++){
	  int k=(j+1)%hull.size();
	  join2(i,hull[j],hull[k]);
	}
	return;
      }
    }
    for(int i=2;i<hull.size();i++){
      join1(hull[0],hull[i-1],hull[i]);
    }
  }else{
    //printf("Convex hull has two types\n");
    std::rotate(hull.begin(),hull.begin()+flip,hull.end());
    flip=std::find_if(hull.begin(),hull.end(),[&hull](int i){return ts[i]!=ts[hull[0]];})-hull.begin();
    for(int i=flip;i<hull.size();i++){
      if(ts[hull[i]]==ts[hull[0]]){
	fail();
      }
    }
    for(int i=1;i<flip;i++){
      connect(hull[i-1],hull[i]);
      join2(hull[flip],hull[i-1],hull[i]);
    }
    for(int i=flip+1;i<hull.size();i++){
      connect(hull[i-1],hull[i]);
      join2(hull[0],hull[i-1],hull[i]);
    }
  }
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    ps[i].read();
    scanf("%d",&ts[i]);
  }
  solve();
  output();
  return 0;
}