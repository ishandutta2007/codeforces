#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> lines;

int main(){
  int minframe=0;
  int shift=-1;
  while(!std::cin.eof()){
    std::string line;
    std::getline(std::cin,line);
    if(std::cin.eof()){
      break;
    }
    minframe=std::max<int>(minframe,line.length());
    lines.push_back(line);
  }
  std::cout<<std::string(minframe+2,'*')<<std::endl;
  for(int i=0;i<lines.size();i++){
    int space=minframe-lines[i].length();
    int lspace=space,rspace;
    if(space%2==1){
      lspace+=shift;
      shift*=-1;
    }
    lspace/=2;
    rspace=space-lspace;
    
    std::cout<<"*"<<std::string(lspace,' ')<<lines[i]<<std::string(rspace,' ')<<"*"<<std::endl;
  }
  std::cout<<std::string(minframe+2,'*')<<std::endl;
  return 0;
}