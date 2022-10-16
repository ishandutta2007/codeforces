#include <iostream>
#include <iomanip>

int main(){
  int hh,mm,H,D,C,N;
  std::cin>>hh>>mm>>H>>D>>C>>N;
  int wake=hh*60+mm;
  double ans;
  if(wake>=20*60){
    ans=(H+N-1)/N*0.8*C;
  }else{
    ans=std::min<double>((H+N-1)/N*C,(H+(20*60-wake)*D+N-1)/N*0.8*C);
  }
  std::cout<<std::setprecision(10)<<ans<<std::endl;
  return 0;
}