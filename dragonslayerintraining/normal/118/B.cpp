#include <iostream>

void drawline(int N,int i){
  for(int j=0;j<N;j++){
    if(j>0){
      std::cout<<" ";
    }
    if((i+j-N)<0){
      std::cout<<" ";
    }else{
      std::cout<<(i+j-N);
    }
  }
  for(int j=N;j>=0;j--){
    if((i+j-N)<0){
      break;
    }else{
      std::cout<<" "<<(i+j-N);
    }
  }
  std::cout<<std::endl;
}

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    drawline(N,i);
  }
  for(int i=N;i>=0;i--){
    drawline(N,i);
  }
  return 0;
}