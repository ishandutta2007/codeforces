#include <iostream>
#include <queue>

std::priority_queue<int,std::vector<int>,std::greater<int> > queue;

int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    queue.push(A);
  }
  for(int i=0;i<K;i++){
    int low=queue.top();
    queue.pop();
    queue.push(-low);
  }
  int sum=0;
  for(int i=0;i<N;i++){
    sum+=queue.top();
    queue.pop();
  }
  std::cout<<sum<<std::endl;
  return 0;
}