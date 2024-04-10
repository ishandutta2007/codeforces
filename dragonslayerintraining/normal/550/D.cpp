#include <iostream>

int K;
void outputedge(int a,int b){
  if(b<a){
    return;
  }
  std::cout<<a+1<<" "<<b+1<<std::endl;
  std::cout<<a+K+3<<" "<<b+K+3<<std::endl;
}

int main(){
  std::cin>>K;
  if(K%2==0){
    std::cout<<"NO"<<std::endl;
  }else if(K==1){
    std::cout<<"YES"<<std::endl;
    std::cout<<"2 1"<<std::endl;
    std::cout<<"1 2"<<std::endl;
  }else{
    std::cout<<"YES"<<std::endl;
    std::cout<<2*K+4<<" "<<K*(K+2)<<std::endl;
    std::cout<<1<<" "<<K+3<<std::endl;
    for(int i=0;i<K+2;i++){
      if(i%2==1){
	outputedge(i,(i+1)%(K+2));
      }
      for(int j=2;j<=K;j++){
	outputedge(i,(i+j)%(K+2));
      }
      if((i>0)&&(i%2==0)){
	outputedge(i,(i+K+1)%(K+2));
      }
    }
  }
  return 0;
}