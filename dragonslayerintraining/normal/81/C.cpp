#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::pair<int,int> > scores;
std::vector<int> type;

bool swapped;

int main(){
  int N,A,B;
  std::cin>>N>>A>>B;
  if(A==B){
    for(int i=0;i<A;i++){
      if(i>0){
	std::cout<<" ";
      }
      std::cout<<1;
    }
    for(int i=A;i<N;i++){
      std::cout<<" "<<2;
    }
    std::cout<<std::endl;
    return 0;
  }else if(A>B){
    for(int i=0;i<N;i++){
      int s;
      std::cin>>s;
      scores.push_back(std::pair<int,int>(s,i));
    }
    std::sort(scores.begin(),scores.end());
    type.resize(N);
    for(int i=0;i<A;i++){
      type[scores[i].second]=1;
    }
    for(int i=A;i<N;i++){
      type[scores[i].second]=2;
    }
    for(int i=0;i<N;i++){
      if(i>0){
	std::cout<<" ";
      }
      std::cout<<type[i];
    }
    std::cout<<std::endl;
  }else{
    for(int i=0;i<N;i++){
      int s;
      std::cin>>s;
      scores.push_back(std::pair<int,int>(s,-i));
    }
    std::sort(scores.begin(),scores.end());
    type.resize(N);
    for(int i=0;i<B;i++){
      type[-scores[i].second]=2;
    }
    for(int i=B;i<N;i++){
      type[-scores[i].second]=1;
    }
    for(int i=0;i<N;i++){
      if(i>0){
	std::cout<<" ";
      }
      std::cout<<type[i];
    }
    std::cout<<std::endl;
  }
  return 0;
}