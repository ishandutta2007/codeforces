#include <iostream>
#include <vector>
#include <algorithm>

int ps[200000];

std::vector<int> stk;
int j=1;

int main(){
  int N,K;
  std::cin>>N>>K;
  for(int i=0;i<K;i++){
    std::cin>>ps[i];
    stk.push_back(ps[i]);
    while((!stk.empty())&&(stk.back()==j)){
      stk.pop_back();
      j++;
    }
  }
  if(!std::is_sorted(stk.begin(),stk.end(),std::greater<int>())){
    std::cout<<-1<<std::endl;
    return 0;
  }
  while(!stk.empty()){
    int val=stk.back();
    stk.pop_back();
    for(int x=val-1;x>=j;x--){
      ps[K++]=x;
    }
    j=val+1;
  }
  for(int x=N;x>=j;x--){
    ps[K++]=x;
  }
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<ps[i];
  }
  std::cout<<std::endl;
  return 0;
}