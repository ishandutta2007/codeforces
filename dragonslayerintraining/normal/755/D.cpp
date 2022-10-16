#include <iostream>

int prefix[4000000];
int N;

void add(int i,int v){
  for(i++;i<4000000;i+=i&-i){
    prefix[i]+=v;
  }
}

int sum(int i){
  int ac=0;
  for(i++;i>0;i-=i&-i){
    ac+=prefix[i];
  }
  return ac;
}

int sum_range(int i,int j){
  i%=N;
  j%=N;
  while(i<=0){
    i+=N;
  }
  while(j<=0){
    j+=N;
  }
  if(i<=j){
    return sum(j-1)-sum(i-1);
  }else{
    return sum(N)-sum(i-1)+sum(j-1)-sum(0);
  }
}

int main(){
  int K;
  std::cin>>N>>K;
  K=std::min(K,N-K);

  long long sects=1;
  
  int x=0;
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    int cnt=sum_range(x-K+1,x+K);
    sects+=(cnt+1);
    std::cout<<sects;
    if(x>0){
      add(x,1);
    }else{
      add(N,1);
    }
    x=(x+K)%N;
  }
  std::cout<<std::endl;
  return 0;
}