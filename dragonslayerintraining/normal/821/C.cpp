#include <iostream>
#include <vector>
#include <set>

std::set<int> superposition;
std::vector<int> stack;

int cost;

int next_remove=1;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N*2;i++){
    std::string type;
    std::cin>>type;
    if(type=="add"){
      int V;
      std::cin>>V;
      stack.push_back(V);
    }else if(type=="remove"){
      if(stack.empty()){
	superposition.erase(next_remove);
      }else if(stack.back()==next_remove){
	stack.pop_back();
      }else{
	cost++;
	for(int v:stack){
	  superposition.insert(v);
	}
	stack.clear();
      }
      next_remove++;
    }
  }
  std::cout<<cost<<std::endl;
  return 0;
}