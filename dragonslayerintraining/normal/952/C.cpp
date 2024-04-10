#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

bool bad(std::vector<int> as){
  for(int i=0;i<as.size()-1;i++){
    if(std::abs(as[i]-as[i+1])>=2){
      return true;
    }
  }
  return false;
}

int main(){
  int N;
  std::cin>>N;
  std::vector<int> as;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    as.push_back(A);
  }
  while(!as.empty()){
    if(bad(as)){
      std::cout<<"NO"<<std::endl;
      return 0;
    }
    as.erase(std::max_element(as.begin(),as.end()));
  }
  std::cout<<"YES"<<std::endl;
  return 0;
}