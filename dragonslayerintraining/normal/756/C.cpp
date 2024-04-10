#include <iostream>

int M;

struct cnode{
  int npops;
  int npushs;
  int top;
  cnode():npops(0),npushs(0),top(-1){
  }
}st[400000];

void setop(int w,int L,int R,int p,int t,int x){
  if((p<L)||(p>R)){
    return;
  }
  if(L==R){
    if(t==1){
      //push
      st[w].npops=0;
      st[w].npushs=1;
      st[w].top=x;
    }else{
      st[w].npops=1;
      st[w].npushs=0;
      st[w].top=-1;
    }
  }else{
    setop(w*2+1,L,(L+R)/2,p,t,x);
    setop(w*2+2,(L+R)/2+1,R,p,t,x);
    if(st[w*2+2].npops>=st[w*2+1].npushs){
      st[w].npops=st[w*2+1].npops-st[w*2+1].npushs+st[w*2+2].npops;
      st[w].npushs=st[w*2+2].npushs;
    }else{
      st[w].npops=st[w*2+1].npops;
      st[w].npushs=st[w*2+1].npushs-st[w*2+2].npops+st[w*2+2].npushs;
    }
  }
}

int query(int w,int L,int R,int index){
  if(L==R){
    if(index==0){
      return st[w].top;
    }else{
      return -1;
    }
  }else{
    if(index<st[w*2+2].npushs){
      return query(w*2+2,(L+R)/2+1,R,index);
    }else{
      return query(w*2+1,L,(L+R)/2,index+st[w*2+2].npops-st[w*2+2].npushs);
    }
  }
}

int main(){
  std::cin>>M;
  for(int i=0;i<M;i++){
    int P,T;
    std::cin>>P>>T;
    P--;
    if(T==1){
      //push
      int X;
      std::cin>>X;
      setop(0,0,M-1,P,T,X);
    }else{
      //pop
      setop(0,0,M-1,P,T,-1);
    }
    std::cout<<query(0,0,M-1,0)<<std::endl;
  }
  return 0;
}