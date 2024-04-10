#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <cmath>

#define PI 3.141592653589793238462643383279

std::set<double> angleset;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int X,Y;
    std::cin>>X>>Y;
    angleset.insert(atan2(X,Y));
  }
  std::vector<double> angles(angleset.begin(),angleset.end());
  double best=angles.front()-angles.back()+2*PI;
  for(int i=0;i+1<angles.size();i++){
    best=std::max(best,angles[i+1]-angles[i]);
  }
  std::cout<<std::fixed<<std::setprecision(10)<<360-best*180/PI<<std::endl;
  return 0;
}