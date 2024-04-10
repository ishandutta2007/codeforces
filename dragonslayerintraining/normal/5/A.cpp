#include <iostream>

int numpeople=0;
int cost=0;

int main(){
  while(!std::cin.eof()){
    std::string line;
    std::getline(std::cin,line);
    if(line[0]=='+'){
      numpeople++;
    }else if(line[0]=='-'){
      numpeople--;
    }else{
      for(int i=0;i<line.length();i++){
	if(line[i]==':'){
	  int bytes=line.length()-i-1;
	  cost+=bytes*numpeople;
	}
      }
    }
  }
  std::cout<<cost<<std::endl;
  return 0;
}