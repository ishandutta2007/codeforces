#include <iostream>
#include <vector>

std::vector<std::string> p[4];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string name,type;
    std::cin>>name>>type;
    if(type=="captain"){
      p[3].push_back(name);
    }else if(type=="man"){
      p[2].push_back(name);
    }else if(type=="woman"){
      p[1].push_back(name);
    }else if(type=="child"){
      p[1].push_back(name);
    }else if(type=="rat"){
      p[0].push_back(name);
    }
  }
  for(int i=0;i<4;i++){
    for(int j=0;j<p[i].size();j++){
      std::cout<<p[i][j]<<std::endl;
    }
  }
  return 0;
}