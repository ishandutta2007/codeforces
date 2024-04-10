#include <iostream>
#include <algorithm>

const int INF=1e+7;

std::string genome="ACTG";

int dist(char a,char b){
  int d=std::abs(a-b);
  return std::min(d,26-d);
}

int main(){
  int N;
  std::string str;
  std::cin>>N>>str;
  int best=INF;
  for(int i=0;i+4<=N;i++){
    int cost=0;
    for(int j=0;j<4;j++){
      cost+=dist(str[i+j],genome[j]);
    }
    best=std::min(best,cost);
  }
  std::cout<<best<<std::endl;
  return 0;
}