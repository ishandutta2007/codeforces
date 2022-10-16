#include <cstdio>
#include <vector>
#include <cassert>
#include <cmath>
#include <stdint.h>

struct Point{
  int x,y;
  Point(int x,int y):x(x),y(y){
  }
  void read(){
    scanf("%d %d",&x,&y);
  }
  Point operator-(Point p)const{
    return Point(x-p.x,y-p.y);
  }
  int64_t cross(Point p)const{
    return 1LL*x*p.y-1LL*y*p.x;
  }
};

static int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

static int line(struct Point p){
  return gcd(std::abs(p.x),std::abs(p.y));
}

std::vector<Point> ps;

double inv2[100005]={1};
double ac[60];

int main(){
  int N;
  scanf("%d",&N);
  for(int k=1;k<=N;k++){
    inv2[k]=inv2[k-1]/2;
  }
  for(int i=0;i<N;i++){
    struct Point p(0,0);
    p.read();
    ps.push_back(p);
  }
  double ans=0;
  {
    int64_t twice_area=0;
    for(int i=1;i+1<ps.size();i++){
      twice_area+=(ps[i+1]-ps[0]).cross(ps[i]-ps[0]);
    }
    ans=std::abs(twice_area)/2.0;
  }
  //printf("base=%Lf\n",ans);
  for(int i=0;i<N;i++){
    int64_t twice_area=0;
    for(int len=1;len<std::min(60,N);len++){
      int j=i+len;
      if(len>1){
	twice_area+=(ps[(j-1)%ps.size()]-ps[i]).cross(ps[j%ps.size()]-ps[i]);
      }
      int64_t boundary=line(ps[j%ps.size()]-ps[i]);
      //printf("+ A=%Lf B=%lf\n",area(side),boundary/2.0);
      ac[len]+=std::abs(twice_area)/2.0+boundary/2.0;
    }
  }
  for(int len=1;len<std::min(60,N);len++){
    double rem=ac[len]*(inv2[len+1]-inv2[N])/(1-(N*(N-1)/2+N+1)*inv2[N]);
    //printf("len=%d: %.10lf\n",len,rem);
    ans-=rem;
  }
  printf("%.10lf\n",ans+1);
  return 0;
}