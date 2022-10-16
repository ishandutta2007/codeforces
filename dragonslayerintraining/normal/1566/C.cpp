#include <iostream>

int main(){
  int T;
  std::cin>>T;
  while(T--){
    int N;
    std::cin>>N;
    std::string A,B;
    std::cin>>A>>B;
    int sum=0;
    int state=2;
    for(int i=0;i<A.size();i++){
      if(A[i]!=B[i]){
	sum+=2;
	state=2;
      }else if(A[i]=='0'){
	if(state==1){
	  sum+=2;
	  state=2;
	}else{
	  sum+=1;
	  state=0;
	}
      }else{
	if(state==0){
	  sum+=1;
	  state=2;
	}else{
	  sum+=0;
	  state=1;
	}
      }
    }
    std::cout<<sum<<std::endl;
  }   
}