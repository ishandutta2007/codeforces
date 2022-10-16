#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::pair<int,std::string> > players;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string handle;
    int plus,minus,a,b,c,d,e;
    std::cin>>handle>>plus>>minus>>a>>b>>c>>d>>e;
    players.push_back(std::pair<int,std::string>(plus*100-minus*50+a+b+c+d+e,handle));
  }
  std::cout<<std::max_element(players.begin(),players.end())->second<<std::endl;
  return 0;
}