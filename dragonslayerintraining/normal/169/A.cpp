#include <iostream>
#include <map>

std::map<int,int> as;

int main(){
  int N,A,B;
  std::cin>>N>>A>>B;
  for(int i=0;i<N;i++){
    int X;
    std::cin>>X;
    as[X]++;
  }
  int low=-1,high;
  for(std::pair<int,int> pair:as){
    B-=pair.second;
    if(B<0){
      high=pair.first;
      break;
    }else if(B==0){
      low=pair.first;
    }
  }
  if(low==-1){
    std::cout<<0<<std::endl;
  }else{
    std::cout<<high-low<<std::endl;
  }
  return 0;
}