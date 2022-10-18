#include <iostream>
#include <map>

std::map<std::string,std::string> map;

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::string name,ip;
    std::cin>>name>>ip;
    map[ip]=name;
  }
  for(int i=0;i<M;i++){
    std::string command,ip;
    std::cin>>command>>ip;
    ip.pop_back();
    std::cout<<command<<" "<<ip<<"; #"<<map[ip]<<std::endl;
  }
  return 0;
}