#include <iostream>
#include <vector>
#include <queue>

int main(){
  int T;
  std::cin>>T;
  while(T-->0){
    int N;
    std::cin>>N;
    std::vector<std::vector<int> > come(5000);
    std::vector<int> leave(N);
    std::vector<int> get(N);
    for(int i=0;i<N;i++){
      int L,R;
      std::cin>>L>>R;
      L--,R--;
      come[L].push_back(i);
      leave[i]=R;
    }
    std::queue<int> queue;
    for(int i=0;i<5000;i++){
      for(int s:come[i]){
	queue.push(s);
      }
      while(!queue.empty()&&leave[queue.front()]<i){
	queue.pop();
      }
      if(!queue.empty()){
	int s=queue.front();
	queue.pop();
	get[s]=i+1;
      }
    }
    for(int i=0;i<N;i++){
      if(i>0){
	std::cout<<" ";
      }
      std::cout<<get[i];
    }
    std::cout<<std::endl;
  }
  return 0;
}