#include <iostream>
#include <vector>

int N;
int as[100005];

std::vector<int> inc,dec;

int main(){
  std::cin>>N;
  for(int i=1;i<=N;i++){
    std::cin>>as[i];
  }
  for(int i=1;i<=N;i++){
    for(int k=as[i-1];k<as[i];k++){
      inc.push_back(i);
    }
    for(int k=as[i+1];k<as[i];k++){
      dec.push_back(i);
    }
  }
  std::cout<<inc.size()<<std::endl;
  for(int i=0;i<inc.size();i++){
    std::cout<<inc[i]<<" "<<dec[i]<<std::endl;
  }
  return 0;
}