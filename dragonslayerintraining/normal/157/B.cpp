#include <iostream>
#include <algorithm>
#include <iomanip>

const double PI=3.14159265358979323846;

int rs[100];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>rs[i];
  }
  std::sort(rs,rs+N);
  double area=0;
  for(int i=0;i<N;i++){
    area=PI*rs[i]*rs[i]-area;
  }
  std::cout<<std::setprecision(10)<<area<<std::endl;
  return 0;
}