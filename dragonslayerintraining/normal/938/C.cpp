#include <iostream>
#include <stdint.h>

void solve(){
  int64_t X;
  std::cin>>X;
  if(X==0){
    std::cout<<"1 1"<<std::endl;
    return;
  }
  for(int64_t N=1;N*N-(N/2)*(N/2)<=X;N++){
    int64_t low=1,high=N+1;
    while(high-low>1){
      int64_t mid=(low+high)/2;
      int64_t v=N*N-(N/mid)*(N/mid);
      if(v<X){
	low=mid;
      }else if(v>X){
	high=mid;
      }else{
	std::cout<<N<<" "<<mid<<std::endl;
	return;
      }
    }
  }
  std::cout<<-1<<std::endl;
}

int main(){
  int64_t T;
  std::cin>>T;
  while(T-->0){
    solve();
  }
  return 0;
}