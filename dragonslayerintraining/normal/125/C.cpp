#include <iostream>
#include <vector>

std::vector<std::vector<int> > days;

int main(){
  int N;
  std::cin>>N;
  int k=0;
  for(int j=1;;j++){
    if(k+j>N){
      std::cout<<j<<std::endl;
      break;
    }
    days.resize(j+1);
    for(int i=0;i<j;i++){
      int hobbit=k++;
      days[i].push_back(hobbit);
      days[j].push_back(hobbit);
    }
  }
  for(int i=0;i<days.size();i++){
    for(int k=0;k<days[i].size();k++){
      if(k>0){
	std::cout<<" ";
      }
      std::cout<<days[i][k]+1;
    }
    std::cout<<std::endl;
  }
  return 0;
}