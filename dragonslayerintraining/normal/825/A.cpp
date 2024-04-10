#include <iostream>
#include <vector>

int main(){
  std::vector<int> v;
  v.push_back(0);
  int N;
  std::string S;
  std::cin>>N>>S;
  for(char c:S){
    if(c=='1'){
      v.back()++;
    }else{
      v.push_back(0);
    }
  }
  for(int i=0;i<v.size();i++){
    std::cout<<v[i];
  }
  std::cout<<std::endl;
  return 0;
}