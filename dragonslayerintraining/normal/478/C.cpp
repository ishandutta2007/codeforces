#include <iostream>
#include <algorithm>
#include <cassert>

int as[3];

int main(){
  int tables=0;
  std::cin>>as[0]>>as[1]>>as[2];
  std::sort(as,as+3);
  {
    int d=std::min(as[2]-as[1],as[1]-as[0]);
    tables+=d;
    as[2]-=2*d;
    as[1]-=d;
  }
  assert(as[0]==as[1]||as[1]==as[2]);
  if(as[0]==as[1]){
    int d=std::min(as[0],(as[2]-as[0])/3);
    tables+=d*2;
    as[0]-=d;
    as[1]-=d;
    as[2]-=4*d;
    assert(as[0]==0||(as[2]-as[0])<3);
  }else{//as[1]==as[2]
    int d=(as[2]-as[0])/3;
    tables+=d*2;
    as[1]-=d*3;
    as[2]-=d*3;
    if(as[2]-as[0]==2){
      tables++;
      as[2]-=2;
      as[1]-=1;
    }
  }
  tables+=*std::min_element(as,as+3);
  std::cout<<tables<<std::endl;
  return 0;
}