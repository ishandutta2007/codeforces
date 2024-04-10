#include <iostream>
#include <queue>

int main(){
  std::queue<char> Q;
  int N;
  std::string str;
  std::cin>>N>>str;
  for(int i=0;i<N;i++){
    Q.push(str[i]);
  }
  int antiD=0,antiR=0;
  while(antiD+antiR<N){
    int c=Q.front();
    Q.pop();
    if(c=='D'){
      if(antiD>0){
	antiD--;
      }else{
	antiR++;
	Q.push('D');
      }
    }else{
      if(antiR>0){
	antiR--;
      }else{
	antiD++;
	Q.push('R');
      }
    }
  }
  if(antiD>0){
    std::cout<<'R'<<std::endl;
  }else{
    std::cout<<'D'<<std::endl;
  }
  return 0;
}