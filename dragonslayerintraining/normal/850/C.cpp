#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <stdint.h>

std::map<int64_t,int64_t> primes;

void factor(int64_t N){
  int64_t num=N;
  for(int64_t i=2;i*i<=N;i++){
    if(num%i==0){
      int64_t cnt=0;
      while(num%i==0){
	num/=i;
	cnt++;
      }
      primes[i]|=(1<<cnt);
    }
  }
  if(num>1){
    primes[num]|=(1<<1);
  }
}

std::map<int64_t,int64_t> memo;

int64_t grundy(int64_t x){
  if((x==0)||(x==1)){
    return 0;
  }
  if(memo.count(x)){
    return memo[x];
  }
  std::set<int64_t> ord;
  for(int64_t k=1;(1L<<k)<=x;k++){
    ord.insert(grundy((x&((1<<k)-1))|(x>>k)));
  }
  int64_t mex;
  for(mex=0;ord.count(mex);mex++);
  memo[x]=mex;
  return mex;
}

int64_t N;
int64_t as[100];
int main(){
  std::cin>>N;
  for(int64_t i=0;i<N;i++){
    std::cin>>as[i];
    factor(as[i]);
  }
  int64_t sum=0;
  for(std::pair<int64_t,int64_t> pair:primes){
    sum^=grundy(pair.second);
  }
  if(sum!=0){
    std::cout<<"Mojtaba"<<std::endl;
  }else{
    std::cout<<"Arpa"<<std::endl;
  }
  return 0;
}