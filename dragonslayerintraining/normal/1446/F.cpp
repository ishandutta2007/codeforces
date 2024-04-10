#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>


const double TAU=8*atan(1);

struct Point{
  int x,y;
}ps[100005];

int N;

struct Interval{
  double l,r;
  bool operator<(Interval other)const{
    return r<other.r;
  }
};

int ft[400005];

void update(int i,int v){
  for(i++;i>0;i-=(i&-i)){
    ft[i]+=v;
  }
}

int query(int i){
  int ans=0;
  for(i++;i<=N*4;i+=(i&-i)){
    ans+=ft[i];
  }
  return ans;
}

//count pairs whose line doesn't intersect circle of radius R through origin
long long check(double R){
  std::vector<double> ls;
  std::vector<Interval> itvl;
  for(int i=0;i<N;i++){
    int x=ps[i].x,y=ps[i].y;
    double angle=atan2(y,x);
    double dist=std::hypot(x,y);
    if(dist<R) continue;
    double theta=std::acos(R/dist);
    double l=angle-theta,r=angle+theta;
    if(r<0){
      l+=TAU,r+=TAU;
    }
    if(r>TAU){
      l-=TAU,r-=TAU;
    }
    ls.push_back(l-TAU);
    ls.push_back(l);
    ls.push_back(r-TAU);
    ls.push_back(r);
    itvl.push_back(Interval{l,r});
  }
  std::sort(ls.begin(),ls.end());
  std::sort(itvl.begin(),itvl.end());
  auto cps=[&](double theta){
    return std::lower_bound(ls.begin(),ls.end(),theta)-ls.begin();
  };
  long long ans=0;
  std::fill(ft,ft+N*4+1,0);
  for(auto it:itvl){
    int l=cps(it.l-TAU),r=cps(it.r-TAU);
    update(l,-1);
    update(r,1);
  }
  for(auto it:itvl){
    int l=cps(it.l),r=cps(it.r);
    ans+=query(l);
    update(l,-1);
    update(r,1);
  }
  return ans;
}

int main(){
  long long K;
  scanf("%d %lld",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d %d",&ps[i].x,&ps[i].y);
  }
  double low=0,high=1e5;
  for(int it=0;it<40;it++){
    double mid=(low+high)/2;
    if(N*(N-1LL)/2-check(mid)>=K){
      high=mid;
    }else{
      low=mid;
    }
  }
  printf("%.10lf\n",low);
}