#include <iostream>
#include <map>

std::map<int,int> count;
int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int bar;
    std::cin>>bar;
    count[bar]++;
  }
  int tallest=0;
  for(std::map<int,int>::iterator it=count.begin();it!=count.end();it++){
    tallest=std::max(tallest,it->second);
  }
  std::cout<<tallest<<" "<<count.size()<<std::endl;
  
  return 0;
}