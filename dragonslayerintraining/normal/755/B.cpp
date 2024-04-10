#include <iostream>
#include <set>
#include <string>

int main(){
  int N,M;
  std::cin>>N>>M;
  std::set<std::string> p1,p2,both;
  for(int i=0;i<N;i++){
    std::string str;
    std::cin>>str;
    p1.insert(str);
  }
  for(int i=0;i<M;i++){
    std::string str;
    std::cin>>str;
    p2.insert(str);
    if(p1.count(str)){
      both.insert(str);
    }
  }
  int p1_size=p1.size()-both.size();
  int p2_size=p2.size()-both.size();
  int both_size=both.size();
  if(p1_size>p2_size){
    std::cout<<"YES"<<std::endl;
  }else if(p1_size<p2_size){
    std::cout<<"NO"<<std::endl;
  }else if(both_size%2==0){
    std::cout<<"NO"<<std::endl;
  }else{
    std::cout<<"YES"<<std::endl;
  }
  return 0;
}