#include <iostream>
#include <vector>
#include <stdint.h>

struct segtree{
  int st[400000];
  int lazy[400000];
  int N;
  segtree(int N):N(N){
    for(int i=0;i<400000;i++){
      st[i]=0;
      lazy[i]=0;
    }
  }

  void push(int w,int L,int R){
    if(lazy[w]){
      st[w]=R-L-st[w];
      if(R-L>1){
	lazy[w*2+1]^=lazy[w];
	lazy[w*2+2]^=lazy[w];
      }
      lazy[w]=0;
    }
  }

  int toggle(int w,int L,int R,int a,int b){
    if((b<=L)||(a>=R)){
      return 0;
    }
    push(w,L,R);
    if((a<=L)&&(b>=R)){
      lazy[w]^=1;
      return R-L-2*st[w];
    }
    int M=(L+R)/2;
    int delta=0;
    delta+=toggle(w*2+1,L,M,a,b);
    delta+=toggle(w*2+2,M,R,a,b);
    st[w]+=delta;
    return delta;
  }

  void toggle(int a,int b){
    toggle(0,0,N,a,b);
  }

  int query(int w,int L,int R,int a,int b){
    if((b<=L)||(a>=R)){
      return 0;
    }
    push(w,L,R);
    if((a<=L)&&(b>=R)){
      return st[w];
    }
    int M=(L+R)/2;
    return query(w*2+1,L,M,a,b)
      +query(w*2+2,M,R,a,b);
  }
  int query(int a,int b){
    return query(0,0,N,a,b);
  }
};

int main(){
  int N;
  std::cin>>N;
  std::vector<struct segtree> sts;
  for(int i=0;i<20;i++){
    sts.emplace_back(segtree(N));
  }
  for(int i=0;i<N;i++){
    int A;
    std::cin>>A;
    for(int k=0;k<20;k++){
      if(A&(1<<k)){
	sts[k].toggle(i,i+1);
      }
    }
  }
  /*
  for(int i=0;i<N;i++){
    std::cout<<i+1<<"\t"<<st.query(i,i+1)<<std::endl;
  }
  */
  int M;
  std::cin>>M;
  for(int i=0;i<M;i++){
    int T;
    std::cin>>T;
    switch(T){
    case 1:{
      int L,R;
      std::cin>>L>>R;
      int64_t ac=0;
      for(int k=19;k>=0;k--){
	ac=ac*2+sts[k].query(L-1,R);
      }
      std::cout<<ac<<std::endl;
      break;
    }
    case 2:{
      int L,R,X;
      std::cin>>L>>R>>X;
      for(int k=0;k<20;k++){
	if(X&(1<<k)){
	  sts[k].toggle(L-1,R);
	}
      }
      break;
    }
    }
  }
  return 0;
}