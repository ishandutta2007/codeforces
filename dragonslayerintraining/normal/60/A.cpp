#include <iostream>
#include <cstdio>
#include <algorithm>

int main(){
  int N,M;
  std::cin>>N>>M;
  int left=1,right=N;
  std::string line;
  std::getline(std::cin,line);
  for(int i=0;i<M;i++){
    std::string line;
    std::getline(std::cin,line);
    int val;
    if(sscanf(line.c_str(),"To the left of %d",&val)>0){
      right=std::min(right,val-1);
    }else if(sscanf(line.c_str(),"To the right of %d",&val)>0){
      left=std::max(left,val+1);
    }
  }
  if(left>right){
    std::cout<<-1<<std::endl;
  }else{
    std::cout<<right-left+1<<std::endl;
  }
  return 0;
}