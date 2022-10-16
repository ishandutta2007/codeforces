#include <iostream>
#include <vector>
#include <cassert>

int won[50];
int lost[50];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<(N*(N-1)/2-1);i++){
    int A,B;
    std::cin>>A>>B;
    won[A-1]++;
    lost[B-1]++;
  }
  std::vector<int> left;
  for(int i=0;i<N;i++){
    if(won[i]+lost[i]<N-1){
      left.push_back(i);
    }
  }
  assert(left.size()==2);
  if(won[left[0]]>won[left[1]]){
    std::cout<<left[0]+1<<" "<<left[1]+1<<std::endl;
  }else{
    std::cout<<left[1]+1<<" "<<left[0]+1<<std::endl;
  }
  
  return 0;
}