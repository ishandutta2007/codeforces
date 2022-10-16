#include <iostream>
#include <queue>

int as[1000];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<M;i++){
    std::cin>>as[i];
  }
  int price1=0,price2=0;
  {
    std::priority_queue<int> left;
    for(int i=0;i<M;i++){
      left.push(as[i]);
    }
    for(int i=0;i<N;i++){
      int next=left.top();
      left.pop();
      price1+=next;
      left.push(next-1);
    }
  }
  {
    std::priority_queue<int> left;
    for(int i=0;i<M;i++){
      left.push(-as[i]);
    }
    for(int i=0;i<N;i++){
      int next=-left.top();
      left.pop();
      price2+=next;
      if(next>1){
	left.push(-(next-1));
      }
    }
  }
  std::cout<<price1<<" "<<price2<<std::endl;
  return 0;
}