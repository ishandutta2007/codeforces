#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <functional>

using ll = long long;


struct Point{
  int x,y;
  bool operator<(Point p)const{
    return std::tie(x,y)<std::tie(p.x,p.y);
  }
  Point operator-(Point p)const{
    return Point{x-p.x,y-p.y};
  }
  ll cross(Point p)const{
    return 1LL*x*p.y-1LL*y*p.x;
  }
};
      

int ts[300005];
int qs[300005];
int end[300005];
int N;

std::vector<Point> ch[2*300000];

void ch_append(std::vector<Point>& ch,Point p){
  while(ch.size()>=2&&(ch[ch.size()-2]-p).cross(ch[ch.size()-1]-p)>=0){
    ch.pop_back();
  }
  ch.push_back(p);
}
  
ll ch_query(const std::vector<Point>& ch,int q){
  if(ch.empty()) return LLONG_MIN;
  int l=0,r=ch.size()-1;
  while(l<r){
    int m=(l+r)/2;
    if(1LL*ch[m].x*q+ch[m].y<1LL*ch[m+1].x*q+ch[m+1].y){
      l=m+1;
    }else{
      r=m;
    }
  }
  return 1LL*ch[l].x*q+ch[l].y;
}

int main(){
  std::vector<std::pair<Point,int> > points;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ts[i]);
    if(ts[i]==1){
      int A,B;
      scanf("%d %d",&A,&B);
      end[i]=N;
      points.emplace_back(Point{A,B},i);
    }else if(ts[i]==2){
      int J;
      scanf("%d",&J);
      J--;
      end[J]=i;
    }else{
      scanf("%d",&qs[i]);
    }
  }
  std::sort(points.begin(),points.end());
  for(auto obj:points){
    int l=obj.second;
    auto p=obj.first;
    int r=end[l];
    //printf("(%d,%d): [%d,%d)\n",p.x,p.y,l,r);
    for(l+=N,r+=N;l<r;l>>=1,r>>=1){
      if(l&1) ch_append(ch[l++],p);
      if(r&1) ch_append(ch[--r],p);
    }
  }
  for(int i=0;i<N;i++){
    if(ts[i]==3){
      int Q=qs[i];
      ll best=LLONG_MIN;
      for(int j=i+N;j>0;j>>=1){
	best=std::max(ch_query(ch[j],Q),best);
      }
      if(best==LLONG_MIN){
	printf("EMPTY SET\n");
      }else{
	printf("%lld\n",best);
      }
    }
  }
}