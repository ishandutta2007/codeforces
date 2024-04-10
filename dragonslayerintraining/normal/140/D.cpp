#include <iostream>
#include <algorithm>

int as[100];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::sort(as,as+N);
  int time=10;
  int penalty=0;
  int i;
  for(i=0;i<N;i++){
    time+=as[i];
    if(time>12*60){
      break;
    }
    if(time>6*60){
      penalty+=time-6*60;
    }
  }
  std::cout<<i<<" "<<penalty<<std::endl;
  return 0;
}