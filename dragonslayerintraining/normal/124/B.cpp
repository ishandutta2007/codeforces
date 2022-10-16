#include <iostream>
#include <algorithm>
#include <vector>

int N,K;
std::string array[8];

int main(){
  std::cin>>N>>K;
  for(int i=0;i<N;i++){
    std::cin>>array[i];
  }
  std::vector<int> perm;
  for(int i=0;i<K;i++){
    perm.push_back(i);
  }
  int diff=1e9;
  do{
    int min=1e9,max=0;
    for(int i=0;i<N;i++){
      int num=0;
      for(int k=0;k<K;k++){
	num=num*10+array[i][perm[k]];
      }
      min=std::min(min,num);
      max=std::max(max,num);
    }
    diff=std::min(diff,max-min);
  }while(std::next_permutation(perm.begin(),perm.end()));
  std::cout<<diff<<std::endl;
  return 0;
}