#include <iostream>
#include <vector>

std::vector<int> vs;

int main(){
  std::string str;
  std::cin>>str;
  int last=0;
  int open=0;
  for(int i=0;i<str.length();i++){
    if(str[i]=='#'){
      last=i;
      str[i]=')';
      vs.push_back(1);
    }
    if(str[i]=='('){
      open++;
    }else{
      open--;
    }
    if(open<0){
      std::cout<<-1<<std::endl;
      return 0;
    }
  }
  vs.back()+=open;
  open=0;
  for(int i=0;i<str.length();i++){
    if(i==last){
      open-=vs.back();
    }else if(str[i]=='('){
      open++;
    }else{
      open--;
    }
    if(open<0){
      std::cout<<-1<<std::endl;
      return 0;
    }
  }
  for(int v:vs){
    std::cout<<v<<std::endl;
  }
  return 0;
}