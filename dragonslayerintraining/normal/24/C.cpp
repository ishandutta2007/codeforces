#include <iostream>

long long N,J;

struct cpoint{
  long long x,y;
  cpoint():x(0),y(0){
  }
  cpoint(long long x,long long y):x(x),y(y){
  }
}M0,A[200000];

struct caffine{
  long long mx,my;
  long long bx,by;
  caffine():mx(1),my(1),bx(0),by(0){
  };
  caffine(long long mx,long long my,long long bx,long long by):mx(mx),my(my),bx(bx),by(by){
  }
  caffine(struct cpoint p):mx(-1),my(-1),bx(2*p.x),by(2*p.y){
    
  }
  struct cpoint operator()(struct cpoint p){
    return cpoint(p.x*mx+bx,p.y*my+by);
  }
  struct caffine operator()(struct caffine a){
    return caffine(mx*a.mx,my*a.my,
		   bx+mx*a.bx,by+my*a.by);
  }
}affine[200000];

struct caffine cycle[61];

int main(){
  std::cin>>N>>J;
  std::cin>>M0.x>>M0.y;
  for(int i=0;i<N;i++){
    std::cin>>A[i].x>>A[i].y;
  }
  for(int i=1;i<=N;i++){
    affine[i]=caffine(A[i-1])(affine[i-1]);
  }
  cycle[0]=affine[N];
  for(int i=1;i<61;i++){
    cycle[i]=cycle[i-1](cycle[i-1]);
  }
  int quot=J/N,rem=J%N;

  for(int k=60;k>=0;k--){
    if(quot&(1ll<<k)){
      M0=cycle[k](M0);
    }
  }
  M0=affine[rem](M0);

  std::cout<<M0.x<<" "<<M0.y<<std::endl;
  
  return 0;
}