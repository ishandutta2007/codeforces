#include <iostream>


int N;

int counts[8];

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    int X;
    std::cin>>X;
    counts[X]++;
  }
  if((counts[5]==0)&&(counts[7]==0)&&
     (counts[1]==counts[2]+counts[3])&&
     (counts[1]==counts[4]+counts[6])&&
     (counts[2]>=counts[4])){
    for(int i=0;i<counts[4];i++){
      std::cout<<"1 2 4"<<std::endl;
    }
    for(int i=0;i<counts[3];i++){
      std::cout<<"1 3 6"<<std::endl;
    }
    for(int i=0;i<N/3-counts[4]-counts[3];i++){
      std::cout<<"1 2 6"<<std::endl;
    }
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}