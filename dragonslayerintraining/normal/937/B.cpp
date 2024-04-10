#include <iostream>
#include <queue>
#include <stdint.h>

int main(){
  std::priority_queue<std::pair<int64_t,int64_t> > queue;
  int64_t P,Y;
  std::cin>>P>>Y;
  int64_t X=P;
  for(int64_t i=2;i<=P;i++){
    if(i*i>Y){
      X=i;
      break;
    }
    queue.emplace(Y/i*i,i);
  }
  while(Y>P&&queue.top().first>=Y){
    if(queue.top().first==Y){
      Y--;
      if(X*X==Y){
	queue.emplace(Y,X--);
      }
    }
    int64_t a=queue.top().first;
    int64_t i=queue.top().second;
    queue.pop();
    queue.emplace(a-i,i);
  }
  if(Y>P){
    std::cout<<Y<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}