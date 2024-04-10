#include <iostream>
#include <vector>

int main(){
  int N;
  std::cin>>N;
  std::vector<char> v;
  for(int i=0;i<N;i++){
    while(true){
      char c=std::cin.get();
      if((c!='0')&&(c!='1')){
	continue;
      }
      if(v.size()&&(c!=v.back())){
	v.pop_back();
      }else{
	v.push_back(c);
      }
      break;
    }
  }
  std::cout<<v.size()<<std::endl;
  return 0;
}