#include <iostream>
#include <vector>
#include <stdint.h>

std::vector<int64_t> v;

int main(){
  int K;
  std::string str;
  std::cin>>K;
  std::cin>>str;
  int last=-1;
  for(int i=0;i<str.length();i++){
    if(str[i]=='1'){
      v.push_back(i-last);
      last=i;
    }
  }
  v.push_back(str.size()-last);
  int64_t total=0;
  if(K>0){
    for(int i=0;i+K<v.size();i++){
      total+=v[i]*v[i+K];
    }
  }else{
    for(int i=0;i<v.size();i++){
      total+=v[i]*(v[i]-1)/2;
    }
  }
  std::cout<<total<<std::endl;
  return 0;
}