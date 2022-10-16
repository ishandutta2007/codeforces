#include <iostream>
#include <vector>

std::vector<std::pair<int,int> > v;

int main(){
  int X,Y,A,B;
  std::cin>>X>>Y>>A>>B;
  for(int c=A;c<=X;c++){
    for(int d=B;d<=std::min(Y,c-1);d++){
      v.push_back(std::make_pair(c,d));
    }
  }
  std::cout<<v.size()<<std::endl;
  for(std::pair<int,int> p:v){
    std::cout<<p.first<<" "<<p.second<<std::endl;
  }
  return 0;
}