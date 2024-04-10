#include <iostream>

long long query(long long N,long long R){
  long long size=2;
  for(long long num=N;num>1;num/=2){
    size*=2;
  }
  size--;
  long long repeats=0;
  long long cnt=0;
  for(long long num=N;num>0;num/=2,size/=2){
    //std::cout<<num<<"\t"<<size<<"\t"<<repeats<<"\t"<<cnt<<"\t"<<L<<"\t"<<R<<std::endl;
    long long middle=(size/2);
    cnt+=repeats*(num%2);
    repeats=repeats*2;
    if(R>=middle){
      cnt+=(num%2);
      R-=(middle+1);
      repeats++;
    }
  }
  return cnt;
}

int main(){
  long long N,L,R;
  std::cin>>N>>L>>R;
  L--,R--;
  std::cout<<query(N,R)-query(N,L-1)<<std::endl;
}