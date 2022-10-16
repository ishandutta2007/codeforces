#include <iostream>

int N,K;
std::string str;

int cnt[256];

int main(){
  std::cin>>N>>K;
  std::cin>>str;
  for(char c:str){
    cnt[c]++;
  }
  char last='a';
  while(cnt[last]<=K&&last<='z'){
    K-=cnt[last];
    last++;
  }
  for(char c:str){
    if(c<last){
      continue;
    }else if(c==last&&K>0){
      K--;
    }else{
      std::cout<<c;
    }
  }
  std::cout<<std::endl;
  return 0;
  
}