#include <iostream>
#include <set>

std::set<int> amulets;
std::set<int> taken;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    if(i>0){
      std::string starstar;
      std::cin>>starstar;
    }
    int A,B;
    std::cin>>A>>B;
    int num=A*100+B%10*10+B/10;
    if(!taken.count(num)){
      amulets.insert(num);
      for(int j=0;j<4;j++){
	taken.insert(num);
	num=(num/1000)+(num*10%10000);
      }
    }
  }
  std::cout<<amulets.size()<<std::endl;
  return 0;
}