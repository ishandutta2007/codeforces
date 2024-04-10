#include <iostream>

int main(){
  int T;
  std::cin>>T;
  while(T--){
    std::string S;
    std::cin>>S;
    int cnt=0;
    for(int i=0;i<S.length();i++){
      if(S[i]=='0'){
	if(i==0||S[i-1]!='0'){
	  cnt++;
	}
      }
    }
    std::cout<<std::min(cnt,2)<<std::endl;
  }
}