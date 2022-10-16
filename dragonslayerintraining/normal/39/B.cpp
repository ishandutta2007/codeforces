#include <iostream>
#include <vector>

int N;
int target=1;

std::vector<int> v;

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    int a;
    std::cin>>a;
    if(a==target){
      v.push_back(2001+i);
      target++;
    }
  }
  std::cout<<v.size()<<std::endl;
  if(v.empty()){
    return 0;
  }
  for(int i=0;i<v.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<v[i];
  }
  std::cout<<std::endl;
  return 0;
}