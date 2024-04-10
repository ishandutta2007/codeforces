#include <iostream>
#include <map>

std::map<int,int> counts;

int as[100000];

int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  int L=0;
  for(int R=0;R<N;R++){
    counts[as[R]]++;
    if(counts.size()==K){
      while(counts.size()>=K){
	if(--counts[as[L]]==0){
	  counts.erase(as[L]);
	}
	L++;
      }
      std::cout<<L<<" "<<R+1<<std::endl;
      return 0;
    }
  }
  std::cout<<-1<<" "<<-1<<std::endl;
  return 0;
}