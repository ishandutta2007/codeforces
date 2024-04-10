#include <iostream>
#include <vector>

int main(){
  std::string line;
  std::getline(std::cin,line);

  int longest=0;
  int count=1;
  std::vector<int> stk;

  stk.push_back(0);
  for(int i=0;i<line.size();i++){
    if(line[i]=='('){
      stk.push_back(i+1);
    }else{
      stk.pop_back();
      if(!stk.empty()){
	int newlen=i-stk.back()+1;
	if(longest<newlen){
	  longest=newlen;
	  count=1;
	}else if(longest==newlen){
	  count++;
	}
      }else{
	stk.push_back(i+1);
      }
    }
  }
  std::cout<<longest<<" "<<count<<std::endl;
  
  return 0;
}