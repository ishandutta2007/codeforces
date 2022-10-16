#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>

int64_t cnt=0;
std::vector<std::pair<int64_t,int64_t> > pairs;

int main(){
  int64_t N;
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    std::string str;
    std::cin>>str;
    int64_t s=0,h=0;
    for(char c:str){
      if(c=='s'){
	s++;
      }else{
	h++;
	cnt+=s;
      }
    }
    pairs.emplace_back(s,h);
  }
  std::sort(pairs.begin(),pairs.end(),[](std::pair<int64_t,int64_t> a,std::pair<int64_t,int64_t> b){return a.first*b.second>a.second*b.first;});
  int64_t s=0;
  for(std::pair<int64_t,int64_t> pair:pairs){
    cnt+=s*pair.second;
    s+=pair.first;
  }
  std::cout<<cnt<<std::endl;
  return 0;
}