#include <iostream>

int N,K;
int heights[100000];

int stmax[400000];
int stmin[400000];

void build(int w,int a,int b){
  if(a==b){
    stmax[w]=heights[a];
    stmin[w]=heights[a];
    return;
  }
  build(2*w+1,a,(a+b)/2);
  build(2*w+2,(a+b)/2+1,b);
  stmax[w]=std::max(stmax[2*w+1],stmax[2*w+2]);
  stmin[w]=std::min(stmin[2*w+1],stmin[2*w+2]);
}

int querymax(int w,int a,int b,int L,int R){
  //std::cerr<<"qmax("<<w<<","<<a<<","<<b<<","<<L<<","<<R<<")"<<std::endl;
  if((a>R)||(b<L)){
    return -1e9;
  }
  if((a>=L)&&(b<=R)){
    return stmax[w];
  }
  return std::max(querymax(2*w+1,a,(a+b)/2,L,R),
		  querymax(2*w+2,(a+b)/2+1,b,L,R));
}
int querymin(int w,int a,int b,int L,int R){
  //std::cerr<<"qmin("<<w<<","<<a<<","<<b<<","<<L<<","<<R<<")"<<std::endl;
  if((a>R)||(b<L)){
    return 1e9;
  }
  if((a>=L)&&(b<=R)){
    return stmin[w];
  }
  return std::min(querymin(2*w+1,a,(a+b)/2,L,R),
		  querymin(2*w+2,(a+b)/2+1,b,L,R));
}
int queryrange(int a,int b){
  //std::cerr<<"max["<<a<<","<<b<<"]="<<querymax(0,0,N-1,a,b)<<std::endl;
  //std::cerr<<"min["<<a<<","<<b<<"]="<<querymin(0,0,N-1,a,b)<<std::endl;
  //std::cerr<<"range["<<a<<","<<b<<"]="<<querymax(0,0,N-1,a,b)-querymin(0,0,N-1,a,b)<<std::endl;
  return querymax(0,0,N-1,a,b)-querymin(0,0,N-1,a,b);
}

int main(){
  std::cin>>N>>K;
  //std::cerr<<"K="<<K<<std::endl;
  for(int i=0;i<N;i++){
    std::cin>>heights[i];
  }
  build(0,0,N-1);
  int best=0;
  int count=0;
  int start=0;
  for(int i=0;i<N;i++){
    while(queryrange(start,i)>K){
      start++;
    }
    //std::cerr<<"["<<start<<","<<i<<"]"<<std::endl;
    if(best<i-start){
      best=i-start;
      count=1;
    }else if(best==i-start){
      count++;
    }
  }
  std::cout<<best+1<<" "<<count<<std::endl;
  
  start=0;
  for(int i=0;i<N;i++){
    while(queryrange(start,i)>K){
      start++;
    }
    //std::cerr<<"["<<start<<","<<i<<"]"<<std::endl;
    if(i-start==best){
      std::cout<<start+1<<" "<<i+1<<std::endl;
    }
  }
  
  return 0;
}