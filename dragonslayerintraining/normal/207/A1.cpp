#include <iostream>
#include <queue>
#include <stdint.h>

std::priority_queue<std::pair<int,int> > queue,delay;

struct scientist{
  int k,a,x,y,m;
  bool step(){
    if(--k>0){
      a=(uint64_t(a)*x+y)%m;
      return true;
    }else{
      return false;
    }
  }
};

std::istream& operator>>(std::istream& in,struct scientist& sci){
  return in>>sci.k>>sci.a>>sci.x>>sci.y>>sci.m;
}

std::vector<struct scientist> lists;

std::vector<std::pair<int,int> > opt;
int problems=0;

int main(){
  int N;
  std::cin>>N;
  lists.resize(N);
  for(int i=0;i<N;i++){
    std::cin>>lists[i];
    queue.push(std::make_pair(-lists[i].a,i));
    problems+=lists[i].k;
  }
  int bad=-1;
  while(!queue.empty()){
    while(!queue.empty()){
      int limit=-queue.top().first;
      int index=queue.top().second;
      opt.push_back(std::make_pair(limit,index+1));
      queue.pop();
      if(lists[index].step()){
	if(lists[index].a>=limit){
	  queue.push(std::make_pair(-lists[index].a,index));
	}else{
	  delay.push(std::make_pair(-lists[index].a,index));
	}
      }
    }
    bad++;
    while(!delay.empty()){
      queue.push(delay.top());
      delay.pop();
    }
  }
  std::cout<<bad<<std::endl;
  if(problems<=200000){
    for(std::pair<int,int> pair:opt){
      std::cout<<pair.first<<" "<<pair.second<<std::endl;
    }
  }
  return 0;
}