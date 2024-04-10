#include <iostream>
#include <set>

int main(){
  int N;
  std::set<int> set;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int num;
    std::cin>>num;
    set.insert(num);
  }
  if(set.size()<2){
    std::cout<<"NO"<<std::endl;
    return 0;
  }
  std::set<int>::iterator it=set.begin();
  it++;
  std::cout<<*it<<std::endl;
  return 0;
}