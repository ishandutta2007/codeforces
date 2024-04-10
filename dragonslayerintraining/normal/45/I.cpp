#include <iostream>
#include <set>
#include <vector>

std::multiset<int> neg;
std::multiset<int> pos;
std::multiset<int> zero;

std::vector<int> target;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    int cost;
    std::cin>>cost;
    if(cost>0){
      pos.insert(cost);
    }else if(cost<0){
      neg.insert(cost);
    }else{
      zero.insert(cost);
    }
  }
  if((pos.size()>0)||(neg.size()>1)){
    for(std::multiset<int>::iterator it=pos.begin();it!=pos.end();it++){
      target.push_back(*it);
    }
    for(std::multiset<int>::iterator it=neg.begin();it!=neg.end();it++){
      target.push_back(*it);
    }
    if(neg.size()%2==1){
      target.pop_back();
    }
  }else if(zero.size()>0){
    target.push_back(0);
  }else{
    target.push_back(*neg.rbegin());
  }
  for(int i=0;i<target.size();i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<target[i];
  }
  std::cout<<std::endl;
  return 0;
}