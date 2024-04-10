#include <iostream>

int main(){
  int N;
  std::cin>>N;
  int best,worst;
  std::cin>>best;
  worst=best;
  int cnt=0;
  for(int i=1;i<N;i++){
    int score;
    std::cin>>score;
    if(score>best){
      best=score;
      cnt++;
    }
    if(score<worst){
      worst=score;
      cnt++;
    }
  }
  std::cout<<cnt<<std::endl;
  return 0;
}