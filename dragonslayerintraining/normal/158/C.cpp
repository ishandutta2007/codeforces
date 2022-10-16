#include <iostream>
#include <vector>

std::vector<std::string> path;

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::string arg0;
    std::cin>>arg0;
    if(arg0=="pwd"){
      std::cout<<"/";
      for(int i=0;i<path.size();i++){
	std::cout<<path[i]<<"/";
      }
      std::cout<<std::endl;
    }else if(arg0=="cd"){
      std::string to;
      std::cin>>to;
      int i=0;
      if(to[i]=='/'){
	path.clear();
	i++;
      }
      std::string dir;
      for(;i<to.size();i++){
	if(to[i]=='/'){
	  if(dir==".."){
	    path.pop_back();
	  }else{
	    path.push_back(dir);
	  }
	  dir.clear();
	}else{
	  dir+=to[i];
	}
      }
      if(dir==".."){
	path.pop_back();
      }else{
	path.push_back(dir);
      }
      dir.clear();
      
    }
  }
  return 0;
}