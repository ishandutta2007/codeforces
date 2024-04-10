#include <iostream>
#include <algorithm>

int64_t N,K;
int64_t as[100005];
int64_t sorted[100005];

int64_t st[400005];

void build(int64_t w,int64_t L,int64_t R){
  if(L==R){
    st[w]=0;
  }else{
    st[w]=0;
    build(w*2+1,L,(L+R)/2);
    build(w*2+2,(L+R)/2+1,R);
  }
}

void build(){
  build(0,0,N);
}

void enable(int64_t w,int64_t L,int64_t R,int64_t v){
  if((v>sorted[R])||(v<sorted[L])){
    return;
  }
  st[w]++;
  if(L!=R){
    if(sorted[(L+R)/2]>=v){
      enable(w*2+1,L,(L+R)/2,v);
    }else{
      enable(w*2+2,(L+R)/2+1,R,v);
    }
  }
}

void enable(int64_t v){
  enable(0,0,N,v);
}

int64_t sum(int64_t w,int64_t L,int64_t R,int64_t v){
  if(v<sorted[L]){
    return 0;
  }
  if(L==R){
    return st[w];
  }else{
    if(sorted[(L+R)/2]>=v){
      return sum(w*2+1,L,(L+R)/2,v);
    }else{
      return st[w*2+1]+sum(w*2+2,(L+R)/2+1,R,v);
    }
  }
}

int64_t sum(int64_t v){
  return sum(0,0,N,v);
}

int main(){
  std::cin>>N>>K;
  for(int64_t i=1;i<=N;i++){
    std::cin>>as[i];
    as[i]+=as[i-1];
    sorted[i]=as[i];
  }
  std::sort(sorted,sorted+N+1);
  int64_t low=-1e18,high=1e18;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    build();
    int64_t cnt=0;
    for(int64_t i=0;i<=N;i++){
      cnt+=sum(as[i]-mid);
      enable(as[i]);
    }
    if(cnt>=K){
      low=mid;
    }else{
      high=mid;
    }
  }
  std::cout<<low<<std::endl;
  return 0;
}