#include <iostream>
#include <iomanip>

int as[100];

int main(){
  int N,B;
  std::cin>>N>>B;
  bool valid=true;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
    B+=as[i];
  }
  for(int i=0;i<N;i++){
    if(as[i]*N>B){
      valid=false;
    }
  }
  if(!valid){
    std::cout<<-1<<std::endl;
    return 0;
  }
  for(int i=0;i<N;i++){
    double C=double(B)/N-as[i];
    std::cout<<std::fixed<<std::setprecision(6)<<C<<std::endl;
  }
  
  return 0;
}