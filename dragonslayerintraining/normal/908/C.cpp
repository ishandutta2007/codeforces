#include <iostream>
#include <cmath>
#include <iomanip>

int xs[1000];
double ys[1000];

int main(){
  int N,R;
  std::cin>>N>>R;
  int D=R*2;
  for(int i=0;i<N;i++){
    std::cin>>xs[i];
    ys[i]=R;
    for(int j=0;j<i;j++){
      int dx=xs[j]-xs[i];
      if(dx*dx<=D*D){
	ys[i]=std::max(ys[i],ys[j]+std::sqrt(D*D-dx*dx));
      }
    }
  }
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<std::fixed<<std::setprecision(10)<<ys[i];
  }
  std::cout<<std::endl;
  return 0;
}