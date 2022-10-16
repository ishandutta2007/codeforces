#include <iostream>
#include <cmath>

int as[100000];
int sum=0;

int best;
int index=-1;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int L,R;
    std::cin>>L>>R;
    as[i]=L-R;
    sum+=as[i];
  }
  best=std::abs(sum);
  for(int i=0;i<N;i++){
    int score=std::abs(sum-2*as[i]);
    if(score>best){
      index=i;
      best=score;
    }
  }
  std::cout<<index+1<<std::endl;
  return 0;
}