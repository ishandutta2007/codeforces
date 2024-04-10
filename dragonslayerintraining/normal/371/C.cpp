#include <iostream>
#include <stdint.h>

const int64_t INF=1e15;

int main(){
  std::string S;
  int64_t ns[3];
  int64_t ps[3];
  int64_t R;
  std::cin>>S;
  for(int64_t i=0;i<3;i++){
    std::cin>>ns[i];
  }
  for(int64_t i=0;i<3;i++){
    std::cin>>ps[i];
  }
  std::cin>>R;
  int64_t bs[3]={};
  for(char c:S){
    switch(c){
    case 'B':bs[0]++;break;
    case 'S':bs[1]++;break;
    case 'C':bs[2]++;break;
    }
  }
  int64_t low=0,high=INF;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    int64_t cost=0;
    for(int64_t i=0;i<3;i++){
      if(INF/ps[i]<std::max<int64_t>(0,mid*bs[i]-ns[i])){
	cost=INF;
	break;
      }
      cost+=std::max<int64_t>(0,mid*bs[i]-ns[i])*ps[i];
    }
    if(cost<=R){
      low=mid;
    }else{
      high=mid;
    }
  }
  std::cout<<low<<std::endl;
  return 0;
}