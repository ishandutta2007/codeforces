#include <iostream>
#include <algorithm>

int as[4];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::sort(as,as+N);
  if(N==0){
    std::cout<<"YES"<<std::endl;
    std::cout<<1<<std::endl;
    std::cout<<1<<std::endl;
    std::cout<<3<<std::endl;
    std::cout<<3<<std::endl;
  }else if(as[0]*3<as[N-1]){
    std::cout<<"NO"<<std::endl;
  }else if(N==1){
    std::cout<<"YES"<<std::endl;
    std::cout<<as[0]<<std::endl;
    std::cout<<as[0]*3<<std::endl;
    std::cout<<as[0]*3<<std::endl;
  }else if(N==2){
    std::cout<<"YES"<<std::endl;
    std::cout<<4*as[0]-as[1]<<std::endl;
    std::cout<<as[0]*3<<std::endl;
  }else if(N==3){
    if(as[1]+as[2]==4*as[0]){
      std::cout<<"YES"<<std::endl;
      std::cout<<3*as[0]<<std::endl;
    }else if((as[0]+as[1])*3==as[2]*4){
      std::cout<<"YES"<<std::endl;
      std::cout<<as[2]/3<<std::endl;
    }else if(as[2]==as[0]*3){
      std::cout<<"YES"<<std::endl;
      std::cout<<as[0]*4-as[1]<<std::endl;
    }else{
      std::cout<<"NO"<<std::endl;
    }
  }else if(N==4){
    if((as[1]+as[2]==4*as[0])&&(as[3]==3*as[0])){
      std::cout<<"YES"<<std::endl;
    }else{
      std::cout<<"NO"<<std::endl;
    }
  }
  
  return 0;
}