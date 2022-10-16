#include <iostream>

int as[100000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  int up=1,down=1;
  int best=1;
  for(int i=1;i<N;i++){
    if(as[i]<as[i-1]){
      up=down+1;
      down=1;
    }else if(as[i]>as[i-1]){
      down=up+1;
      up=1;
    }else{
      up++,down++;
    }
    best=std::max(best,up);
    best=std::max(best,down);
  }
  std::cout<<best<<std::endl;
  return 0;
}