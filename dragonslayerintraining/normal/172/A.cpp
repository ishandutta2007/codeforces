#include <iostream>

std::string phone[30000];

int main(){
  int N;
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>phone[i];
  }
  for(int i=0;i<phone[0].size();i++){
    char c=phone[0][i];
    for(int j=1;j<N;j++){
      if(phone[j][i]!=c){
	std::cout<<i<<std::endl;
	return 0;
      }
    }
  }
  std::cout<<phone[0].size()<<std::endl;
  return 0;
}