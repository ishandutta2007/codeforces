#include <iostream>
#include <climits>

int main(){
  int N;
  std::cin>>N;
  int min=INT_MAX,town=0;
  for(int i=1;i<=N;i++){
    int X;
    std::cin>>X;
    if(X<min){
      min=X;
      town=i;
    }else if(X==min){
      town=0;
    }
  }
  if(town==0){
    std::cout<<"Still Rozdil"<<std::endl;
  }else{
    std::cout<<town<<std::endl;
  }
  return 0;
}