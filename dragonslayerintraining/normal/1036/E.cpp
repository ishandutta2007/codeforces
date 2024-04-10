#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
     
long long gcd(long long a,long long b){
  return b?gcd(b,a%b):a;
}
     
struct Point{
  long long x,y;
  void read(){
    scanf("%lld %lld",&x,&y);
  }
  Point operator-(Point p)const{
    return {x-p.x,y-p.y};
  }
  Point operator+(Point p)const{
    return {x+p.x,y+p.y};
  }
  long long cross(Point p)const{
    return x*p.y-y*p.x;
  }
  Point operator*(long long s)const{
    return Point{x*s,y*s};
  }
  bool operator<(Point p)const{
    if(y!=p.y) return y<p.y;
    return x<p.x;
  }
};
     
     
std::vector<std::pair<Point,Point> > segs;
std::map<Point,std::set<int> > has;
     
int ccw(Point a,Point b,Point c){
  long long tmp=(b-a).cross(c-a);
  if(tmp>0) return 1;
  if(tmp<0) return -1;
  return 0;
}
     
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    Point a,b;
    a.read(),b.read();
    segs.push_back({a,b});
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      Point a=segs[i].first,b=segs[i].second;
      Point c=segs[j].first,d=segs[j].second;
      if(ccw(a,b,c)*ccw(a,b,d)>0) continue;
      if(ccw(c,d,a)*ccw(c,d,b)>0) continue;
      long long s1=(b-a).cross(d-a);
      long long s2=(c-a).cross(b-a);
      Point num=c*s1+d*s2;
      long long den=s1+s2;
      if(den==0) continue;
      if(num.x%den!=0||num.y%den!=0) continue;
      Point intersection{num.x/den,num.y/den};
      //printf("[(%lld,%lld),(%lld,%lld)]&[(%lld,%lld),(%lld,%lld)]=(%lld,%lld)\n",
      //a.x,a.y,b.x,b.y,c.x,c.y,d.x,d.y,intersection.x,intersection.y);
      has[intersection].insert(i);
      has[intersection].insert(j);
    }
  }
  long long ans=0;
  for(int i=0;i<N;i++){
    long long on=gcd(std::labs(segs[i].first.x-segs[i].second.x),
		     std::labs(segs[i].first.y-segs[i].second.y))+1;
    //printf("seg[%d] has %lld points\n",i,on);
    ans+=on;
  }
  for(auto it:has){
    ans-=it.second.size()-1;
    /*
      for(auto i:it.second){
      printf("(%lld,%lld) is on seg[%d]\n",it.first.x,it.first.y,i);
      }
    */
  }
  printf("%lld\n",ans);
}