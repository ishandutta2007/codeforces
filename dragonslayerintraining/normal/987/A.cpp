#include <iostream>
#include <map>

bool has[6];
char names[6][20]={"Power","Time","Space","Soul","Reality","Mind"};
std::map<std::string,int> map;

int main(){
  map["purple"]=0;
  map["green"]=1;
  map["blue"]=2;
  map["orange"]=3;
  map["red"]=4;
  map["yellow"]=5;
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string str;
    std::cin>>str;
    has[map[str]]=true;
  }
  std::cout<<6-N<<std::endl;
  for(int i=0;i<6;i++){
    if(!has[i]){
      std::cout<<names[i]<<std::endl;
    }
  }
  return 0;
}