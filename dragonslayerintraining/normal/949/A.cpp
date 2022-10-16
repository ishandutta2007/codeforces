#include <iostream>
#include <algorithm>
#include <queue>

int prev[200000];

std::deque<int> zeros,ones;

void recover(int i){
  std::vector<int> res;
  for(;i>=0;i=prev[i]){
    res.push_back(i);
  }
  std::reverse(res.begin(),res.end());
  std::cout<<res.size();
  for(int i=0;i<res.size();i++){
    std::cout<<" "<<res[i]+1;
  }
  std::cout<<std::endl;
}

int main(){
  std::string str;
  std::cin>>str;
  for(int i=0;i<str.length();i++){
    if(str[i]=='0'){
      if(!ones.empty()){
	prev[i]=ones.front();
	ones.pop_front();
      }else{
	prev[i]=-1;
      }
      zeros.push_back(i);
    }else{
      if(zeros.empty()){
	std::cout<<-1<<std::endl;
	return 0;
      }
      prev[i]=zeros.front();
      zeros.pop_front();
      ones.push_back(i);
    }
  }
  if(!ones.empty()){
    std::cout<<-1<<std::endl;
    return 0;
  }
  std::cout<<zeros.size()<<std::endl;
  for(int z:zeros){
    recover(z);
  }
  return 0;
}