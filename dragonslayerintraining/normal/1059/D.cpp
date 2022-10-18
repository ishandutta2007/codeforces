#include <cstdio>
#include <cmath>
#include <numeric>
#include <algorithm>

int xs[100005];
int ys[100005];
int N;

bool check(double rad){
  double l=-std::numeric_limits<double>::infinity();
  double r=std::numeric_limits<double>::infinity();
  for(int i=0;i<N;i++){
    double dx2=ys[i]*(rad*2-ys[i]);
    if(dx2<0) return false;
    double dx=std::sqrt(dx2);
    l=std::max(l,xs[i]-dx);
    r=std::min(r,xs[i]+dx);
  }
  return l<=r;
}

int main(){
  scanf("%d",&N);
  int sgn=0;
  for(int i=0;i<N;i++){
    scanf("%d %d",&xs[i],&ys[i]);
    if(ys[i]>0){
      sgn|=1;
    }else{
      sgn|=2;
    }
  }
  if(sgn==3){
    printf("-1\n");
    return 0;
  }
  if(sgn==2){
    for(int i=0;i<N;i++){
      ys[i]=-ys[i];
    }
  }
  double low=0,high=1e14;
  for(int it=0;it<100;it++){
    double mid=(low+high)/2;
    if(mid==low||mid==high) break;
    if(check(mid)){
      high=mid;
    }else{
      low=mid;
    }
  }  
  printf("%.10lf\n",low);
}