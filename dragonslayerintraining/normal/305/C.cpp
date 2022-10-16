#include <iostream>
#include <map>

int main(){
  int N;
  std::cin>>N;
  std::map<int,int> bits;
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    bits[A]++;
  }
  int cnt=0;
  for(auto pair:bits){
    if(pair.second>1){
      bits[pair.first+1]+=pair.second/2;
    }
    if(pair.second%2==1){
      cnt++;
    }
  }
  std::cout<<bits.rbegin()->first-cnt+1<<std::endl;
  return 0;
}