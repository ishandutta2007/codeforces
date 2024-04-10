#include <iostream>
#include <vector>
#include <bitset>
#include <stdint.h>
#include <cassert>

std::bitset<5000> dp[5001];
int64_t as[5001];
int N,K,V;

void pour(int64_t times,int from,int to){
  if(times){
    std::cout<<times<<" "<<from<<" "<<to<<std::endl;
    int64_t amount=std::min(as[from],times*K);
    as[from]-=amount;
    as[to]+=amount;
  }
}

int main(){
  std::cin>>N>>K>>V;
  int64_t total=0;
  for(int i=1;i<=N;i++){
    std::cin>>as[i];
    total+=as[i];
  }
  if(total<V){
    std::cout<<"NO"<<std::endl;
    return 0;
  }
  dp[0][0]=1;
  for(int i=1;i<=N;i++){
    int res=as[i]%K;
    dp[i]=dp[i-1]|(dp[i-1]<<res)|(dp[i-1]>>(K-res));
  }
  if(dp[N][V%K]==0){
    std::cout<<"NO"<<std::endl;
    return 0;
  }
  std::cout<<"YES"<<std::endl;
  
  std::vector<int> use;
  int curr=V%K;
  for(int i=N;i>0;i--){
    int alt=(curr+K-as[i]%K)%K;
    if(dp[i-1][alt]!=0){
      use.push_back(i);
      curr=alt;
    }
  }
  int target;
  if(use.empty()){
    pour((as[1]+K-1)/K,1,2);
    target=1;
  }else{
    target=use.back();
    use.pop_back();
    for(int i:use){
      pour((as[i]+K-1)/K,i,target);
    }
  }
  assert(as[target]%K==V%K);
  if(as[target]<V){
    int pile=0;
    for(int i=1;i<=N;i++){
      if(i==target) continue;
      if(as[i]!=0){
	if(pile){
	  pour((as[pile]+K-1)/K,pile,i);
	}
	pile=i;
      }
    }
    pour((V-as[target])/K,pile,target);
  }else if(as[target]>V){
    pour((as[target]-V)/K,target,target%2+1);
  }
  return 0;
}