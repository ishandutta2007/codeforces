#include <iostream>
#include <map>

std::map<std::string,int> next;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string name;
    std::cin>>name;
    if(!next.count(name)){
      std::cout<<"OK"<<std::endl;
      next[name]=1;
    }else{
      std::cout<<name<<next[name]<<std::endl;
      next[name]++;
    }
  }
  return 0;
}