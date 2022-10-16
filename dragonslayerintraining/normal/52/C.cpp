#include <cstdio>
#include <iostream>
#include <algorithm>

long long st[1600000];
long long lazy[1600000];
int N;

void push(int w,int L,int R){
  if(L<=R){
    st[w]+=lazy[w];
    if(L<R){
      lazy[w*2+1]+=lazy[w];
      lazy[w*2+2]+=lazy[w];
    }
    lazy[w]=0;
  }
}

long long rmq(int w,int L,int R,int a,int b){
  //std::cerr<<"rmq("<<w<<","<<L<<","<<R<<","<<a<<","<<b<<")"<<std::endl;
  push(w,L,R);
  if((a>R)||(b<L)){
    return 1e9;
  }
  
  if((a<=L)&&(b>=R)){
    return st[w];
  }
  return std::min(rmq(w*2+1,L,(L+R)/2,a,b),
		  rmq(w*2+2,(L+R)/2+1,R,a,b));
}

void inc(int w,int L,int R,int a,int b,int v){
  //std::cerr<<"inc("<<w<<","<<L<<","<<R<<","<<a<<","<<b<<","<<v<<")"<<std::endl;
  push(w,L,R);
  if((a>R)||(b<L)){
    return;
  }
  if((a<=L)&&(b>=R)){
    lazy[w]+=v;
    push(w,L,R);
    return;
  }
  inc(w*2+1,L,(L+R)/2,a,b,v);
  inc(w*2+2,(L+R)/2+1,R,a,b,v);
  if(L!=R){
    st[w]=std::min(st[w*2+1],st[w*2+2]);
  }
}

long long cyclic_rmq(int lf,int rg){
  if(lf<=rg){
    return rmq(0,0,N-1,lf,rg);
  }else{
    return std::min(rmq(0,0,N-1,lf,N-1),
		    rmq(0,0,N-1,0,rg));
  }
}

void cyclic_inc(int lf,int rg,int v){
  if(lf<=rg){
    inc(0,0,N-1,lf,rg,v);
  }else{
    inc(0,0,N-1,lf,N-1,v);
    inc(0,0,N-1,0,rg,v);
  }
}

char str[100];

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int a;
    scanf("%d",&a);
    inc(0,0,N-1,i,i,a);
  }
  int M;
  scanf("%d\n",&M);
  for(int i=0;i<M;i++){
    int lf,rg,v;
    fgets(str,sizeof(str),stdin);
    if(sscanf(str,"%d %d %d",&lf,&rg,&v)==3){
      cyclic_inc(lf,rg,v);
    }else if(sscanf(str,"%d %d",&lf,&rg)){
      std::cout<<cyclic_rmq(lf,rg)<<std::endl;
    }else{
      std::cerr<<"Unrecognized format"<<std::endl;
    }
  }
  
  return 0;
}