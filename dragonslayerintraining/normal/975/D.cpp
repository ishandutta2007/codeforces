#include <cstdio>
#include <map>
#include <vector>
#include <stdint.h>

std::map<int64_t,std::map<std::pair<int64_t,int64_t>,int64_t> > all;
std::map<int64_t,int64_t> total;

int64_t exp=0;

int main(){
  int64_t N,A,B;
  scanf("%I64d %I64d %I64d",&N,&A,&B);
  for(int64_t i=0;i<N;i++){
    int64_t X,VX,VY;
    scanf("%I64d %I64d %I64d",&X,&VX,&VY);
    all[A*VX-VY][std::make_pair(VX,VY)]++;
    total[A*VX-VY]++;
  }
  for(auto line:all){
    int64_t tot=total[line.first];
    for(auto co:line.second){
      exp+=(tot-co.second)*co.second;
    }
  }
  printf("%I64d\n",exp);
  return 0;
}