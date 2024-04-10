#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int N,M,K,T;

std::vector<int> waste;
std::set<int> wasteset;

std::string query(int cell){
  if(wasteset.count(cell)){
    return "Waste";
  }else{
    std::vector<int>::iterator p;
    p=std::upper_bound(waste.begin(),waste.end(),cell);
    switch((cell-(p-waste.begin()))%3){
    case 0:return "Carrots";
    case 1:return "Kiwis";
    case 2:return "Grapes";
    }
  }
}

int main(){
  std::cin>>N>>M>>K>>T;
  for(int i=0;i<K;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    wasteset.insert(A*M+B);
    waste.push_back(A*M+B);
  }
  std::sort(waste.begin(),waste.end());
  for(int i=0;i<T;i++){
    int A,B;
    std::cin>>A>>B;
    A--,B--;
    std::cout<<query(A*M+B)<<std::endl;
  }
  return 0;
}