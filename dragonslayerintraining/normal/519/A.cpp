#include <iostream>
#include <map>

int weight=0;

int main(){
  std::map<char,int> map;
  map['Q']=9;
  map['R']=5;
  map['B']=3;
  map['N']=3;
  map['P']=1;
  map['q']=-9;
  map['r']=-5;
  map['b']=-3;
  map['n']=-3;
  map['p']=-1;
  for(int i=0;i<8;i++){
    std::string line;
    std::cin>>line;
    for(char c:line){
      weight+=map[c];
    }
  }
  if(weight>0){
    std::cout<<"White"<<std::endl;
  }else if(weight<0){
    std::cout<<"Black"<<std::endl;
  }else{
    std::cout<<"Draw"<<std::endl;
  }
  return 0;
}