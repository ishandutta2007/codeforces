#include <iostream>

int main(){
  int N;
  std::cin>>N;
  if(N==1){
    std::cout<<"a"<<std::endl<<"a"<<std::endl
	     <<"b"<<std::endl<<"b"<<std::endl;
    return 0;
  }else if(N%2==0){
    for(int i=0;i<N;i++){
      std::cout<<char('a'+i/2%2);
    }
    std::cout<<std::endl;
    for(int i=0;i<N;i++){
      std::cout<<((i==0)?'z':(i==N-1)?'y':char('c'+(i+1)/2%2));
    }
    std::cout<<std::endl;
    for(int i=0;i<N;i++){
      std::cout<<((i==0)?'z':(i==N-1)?'y':char('e'+(i+1)/2%2));
    }
    std::cout<<std::endl;
    for(int i=0;i<N;i++){
      std::cout<<char('a'+i/2%2);
    }
    std::cout<<std::endl;
  }else{
    for(int i=0;i<N;i++){
      std::cout<<((i==0)?'y':char('a'+(i+1)/2%2));
    }
    std::cout<<std::endl;
    for(int i=0;i<N;i++){
      std::cout<<((i==0)?'y':char('c'+(i+1)/2%2));
    }
    std::cout<<std::endl;
    for(int i=0;i<N;i++){
      std::cout<<((i==N-1)?'z':char('e'+i/2%2));
    }
    std::cout<<std::endl;
    for(int i=0;i<N;i++){
      std::cout<<((i==N-1)?'z':char('g'+i/2%2));
    }
    std::cout<<std::endl;
  }
  return 0;
}