#include <iostream>
#include <map>
#include <stdint.h>

std::map<int64_t,int64_t> horiz,verti;
std::map<int64_t,std::map<int64_t,int64_t> > same;

int main(){
  int64_t N;
  std::cin>>N;
  int64_t cnt=0;
  for(int64_t i=0;i<N;i++){
    int64_t X,Y;
    std::cin>>X>>Y;
    cnt+=horiz[X],horiz[X]++;
    cnt+=verti[Y],verti[Y]++;
    cnt-=same[X][Y],same[X][Y]++;
  }
  std::cout<<cnt<<std::endl;
  return 0;
}