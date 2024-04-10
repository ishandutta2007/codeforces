#include <iostream>
#include <set>
#include <cmath>

std::set<std::pair<int,int>> set;

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

int main(){
  int N;
  int X0,Y0;
  std::cin>>N>>X0>>Y0;
  for(int i=0;i<N;i++){
    int X,Y;
    std::cin>>X>>Y;
    X-=X0;
    Y-=Y0;
    int g=gcd(std::abs(X),std::abs(Y));
    X/=g,Y/=g;
    if(std::make_pair(X,Y)<std::make_pair(0,0)){
      X=-X,Y=-Y;
    }
    set.emplace(X,Y);
  }
  std::cout<<set.size()<<std::endl;
  return 0;
}