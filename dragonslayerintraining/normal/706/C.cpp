#include <iostream>
#include <algorithm>
#include <stdint.h>

int64_t cs[100000];
std::string str[100000];
std::string rev[100000];

int64_t best[2][100000];

int main(){
  int64_t N;
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    std::cin>>cs[i];
  }
  for(int64_t i=0;i<N;i++){
    std::cin>>str[i];
    rev[i]=str[i];
    std::reverse(rev[i].begin(),rev[i].end());
  }
  best[0][0]=0;
  best[1][0]=cs[0];
  for(int64_t i=1;i<N;i++){
    best[0][i]=best[1][i]=1e15;
    if(str[i]>=str[i-1]){
      best[0][i]=std::min(best[0][i],best[0][i-1]);
    }
    if(str[i]>=rev[i-1]){
      best[0][i]=std::min(best[0][i],best[1][i-1]);
    }
    if(rev[i]>=str[i-1]){
      best[1][i]=std::min(best[1][i],cs[i]+best[0][i-1]);
    }
    if(rev[i]>=rev[i-1]){
      best[1][i]=std::min(best[1][i],cs[i]+best[1][i-1]);
    }
  }
  int64_t total=std::min(best[0][N-1],best[1][N-1]);
  if(total>5e14){
    std::cout<<"-1"<<std::endl;
  }else{
    std::cout<<total<<std::endl;
  }
  return 0;
}