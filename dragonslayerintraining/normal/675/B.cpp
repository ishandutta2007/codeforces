#include <iostream>

int main(){
  long long N;
  long long as[4];
  std::cin>>N>>as[0]>>as[3]>>as[1]>>as[2];
  long long low=1e9,high=-1e9;
  for(long long i=0;i<4;i++){
    low=std::min(low,as[i]+as[(i+1)%4]);
    high=std::max(high,as[i]+as[(i+1)%4]);
  }
  std::cout<<N*std::max(0LL,N-high+low)<<std::endl;
  return 0;
}