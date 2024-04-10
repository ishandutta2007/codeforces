#include <iostream>
#include <set>

int as[100000];

std::set<int> overall;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>as[i];
  }
  std::set<int> back;
  //'back' stores all possible values of ranges ending at the current node
  //as the begining of the range moves left, each distinct value has at least one more bit set
  //since there can only be 20 bits set, back.size()<=20
  for(int i=0;i<N;i++){
    back.insert(0);
    std::set<int> next;
    for(int val:back){
      next.insert(val|as[i]);
      overall.insert(val|as[i]);
    }
    std::swap(back,next);
  }
  std::cout<<overall.size()<<std::endl;
  return 0;
}