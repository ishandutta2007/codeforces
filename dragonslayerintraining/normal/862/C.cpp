#include <iostream>
#include <vector>

std::vector<int> out;

int main(){
  int N,X;
  std::cin>>N>>X;
  if(N==2){
    if(X==0){
      std::cout<<"NO"<<std::endl;
    }else{
      std::cout<<"YES"<<std::endl;
      std::cout<<0<<std::endl;
      std::cout<<X<<std::endl;
    }
    return 0;
  }
  std::cout<<"YES"<<std::endl;
  for(int i=0;i<(N-1)/4*4;i++){
    out.push_back(((1<<19)^i));
  }
  switch(N%4){
  case 1:
    out.push_back(X);
    break;
  case 0:
    out.push_back(0);
  case 3:
    out.push_back(0);
  case 2:
    out.push_back(0);
    out.push_back(0);
    out[out.size()-1]^=(1<<17)^X;
    out[out.size()-2]^=(1<<18);
    out[out.size()-3]^=(1<<17)^(1<<18);
    break;
  }
  for(int num:out){
    std::cout<<num<<std::endl;
  }
  return 0;
}