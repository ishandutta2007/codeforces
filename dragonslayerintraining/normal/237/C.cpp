#include <iostream>

int isprime[1000001];
int A,B,K;

bool test(int L){
  int cnt=0;
  for(int i=A;i<A+L;i++){
    cnt+=isprime[i];
  }
  if(cnt<K){
    return false;
  }
  for(int i=A+L;i<=B;i++){
    cnt+=isprime[i];
    cnt-=isprime[i-L];
    if(cnt<K){
      return false;
    }
  }
  return true;
}

int main(){
  std::fill(isprime,isprime+1000001,1);
  isprime[1]=0;
  for(int i=2;i<=1000000;i++){
    for(int k=i*2;k<=1000000;k+=i){
      isprime[k]=0;
    }
  }
  std::cin>>A>>B>>K;
  int low=0,high=B-A+1;
  while(high-low>1){
    int mid=(low+high)/2;
    if(test(mid)){
      high=mid;
    }else{
      low=mid;
    }
  }
  if(test(high)){
    std::cout<<high<<std::endl;
  }else{
    std::cout<<-1<<std::endl;
  }
  return 0;
}