#include <iostream>
#include <queue>

std::priority_queue<int> zero;

int main(){
  int N;
  std::cin>>N;
  int score=0,left=1;
  for(int i=0;i<N;i++){
    int A,B;
    std::cin>>A>>B;
    if(B>0){
      score+=A;
      left+=(B-1);
    }else{
      zero.push(A);
    }
  }
  while((left>0)&&(zero.size())){
    score+=zero.top();
    zero.pop();
    left--;
  }
  std::cout<<score<<std::endl;
  return 0;
}