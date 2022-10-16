#include <iostream>
#include <map>
#include <algorithm>

int price[100];
int counts[100];

int main(){
  int N,M;
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>price[i];
  }
  std::map<std::string,int> map;
  for(int i=0;i<M;i++){
    std::string fruit;
    std::cin>>fruit;
    map[fruit]++;
  }
  M=0;
  for(std::map<std::string,int>::iterator it=map.begin();it!=map.end();it++){
    counts[M++]=it->second;
  }
  std::sort(price,price+N);
  std::sort(counts,counts+M);
  int min=0,max=0;
  for(int i=0;i<M;i++){
    min+=counts[i]*price[M-1-i];
  }
  for(int i=0;i<M;i++){
    max+=counts[i]*price[i+N-M];
  }
  std::cout<<min<<" "<<max<<std::endl;
  return 0;
}