#include <iostream>

int cnt[26]={};

int main(){
  int K;
  std::cin>>K;
  std::string str;
  std::cin>>str;
  for(char c:str){
    cnt[c-'a']++;
  }
  for(int i=0;i<26;i++){
    if(cnt[i]%K!=0){
      std::cout<<-1<<std::endl;
      return 0;
    }
    cnt[i]/=K;
  }
  for(int k=0;k<K;k++){
    for(int i=0;i<26;i++){
      for(int j=0;j<cnt[i];j++){
	std::cout<<char('a'+i);   
      }
    }
  }
  std::cout<<std::endl;
  
  return 0;
}