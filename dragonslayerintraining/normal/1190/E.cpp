#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

const double TAU=8*atan(1);

struct Point{
  int x,y;
  Point():x(0),y(0){
  }
  void read(){
    scanf("%d %d",&x,&y);
  }
  double magn(){
    return std::hypot(x,y);
  }
  double arg(){
    return atan2(y,x);
  }
}ps[100005];
int N;

long long next[100005][20];

bool check(double dist,int barriers){
  std::vector<std::pair<double,double> > intervals,monotone;
  for(int i=0;i<N;i++){
    double center=ps[i].arg();
    if(dist>=ps[i].magn()) return false;
    double semi=acos(dist/ps[i].magn());
    while(center+semi<0){
      center+=TAU;
    }
    while(center+semi>=TAU){
      center-=TAU;
    }
    intervals.push_back({center-semi,center+semi});
  }
  std::sort(intervals.begin(),intervals.end(),[](std::pair<double,double> a,std::pair<double,double> b){
      if(a.second!=b.second){
	return a.second<b.second;
      }
      return a.first>b.first;
    });
  double far=-TAU;;
  for(auto it:intervals){
    far=std::max(far,it.first-TAU);
  }
  for(auto it:intervals){
    if(it.first>far){
      monotone.push_back(it);
      far=it.first;
    }
  }
  int j=0;
  for(int i=0;i<monotone.size();i++){
    while(monotone[j%monotone.size()].first+(j/monotone.size())*TAU<=monotone[i].second){
      j++;
    }
    next[i][0]=j;
  }
  for(int k=1;k<20;k++){
    for(int i=0;i<monotone.size();i++){
      next[i][k]=next[next[i][k-1]%monotone.size()][k-1]+next[i][k-1]/monotone.size()*monotone.size();
    }
  }
  for(int i=0;i<monotone.size();i++){
    long long j=i;
    for(int k=0;k<20;k++){
      if(barriers&(1<<k)){
	j=next[j%monotone.size()][k]+j/monotone.size()*monotone.size();
      }
    }
    if(j-i>=monotone.size()) return true;
  }
  return false;
}

int main(){
  int M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    ps[i].read();
  }
  double low=0,high=2e9;
  /*
  for(int i=0;i<N;i++){
    high=std::min(high,ps[i].magn());
  }
  */
  while(high-low>1e-9){
    double mid=(low+high)/2;
    if(check(mid,M)){
      low=mid;
    }else{
      high=mid;
    }
  }
  printf("%.10lf\n",low);
}