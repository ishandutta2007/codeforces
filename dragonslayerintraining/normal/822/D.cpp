#include <iostream>
#include <stdint.h>

#include <cassert>

const int64_t MOD=1000000007;
const int64_t LIM=5000000;

int64_t arr[LIM+1];
int64_t scale[LIM+1];

int main(){
  std::fill(arr,arr+LIM+1,0);
  for(int64_t i=0;i<=LIM;i++){
    scale[i]=i;
  }
  for(int64_t i=2;i<=LIM;i++){
    if(scale[i]==i){
      int64_t combo=(i*(i-1)/2)%MOD;
      for(int64_t p=i;p<=LIM;p*=i){
	for(int64_t k=p;k<=LIM;k+=p){
	  assert(scale[k]%i==0);
	  scale[k]=scale[k]/i;
	  arr[k]=(arr[k]+combo*scale[k])%MOD;
	}
      }
    }
    assert(scale[i]==1);
  }
  int64_t T,L,R;
  std::cin>>T>>L>>R;
  int64_t ac=0;
  for(int64_t i=R;i>=L;i--){
    ac=(ac*T+arr[i])%MOD;
  }
  std::cout<<ac<<std::endl;
  return 0;
}