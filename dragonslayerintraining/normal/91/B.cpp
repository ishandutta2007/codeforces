#include <iostream>
#include <algorithm>

int N;
struct cwalrus{
  int a,i,d;
  struct cagecmp{
    bool operator()(struct cwalrus w1,struct cwalrus w2)const{
      if(w1.a!=w2.a)return w1.a<w2.a;
      return w1.i>w2.i;
    }
  };
  struct cindexcmp{
    bool operator()(struct cwalrus w1,struct cwalrus w2)const{
      return w1.i>w2.i;
    }
  };
}walrus[100000];


struct cwalrus::cagecmp agecmp;
struct cwalrus::cindexcmp indexcmp;

int main(){
  std::cin>>N;
  for(int i=0;i<N;i++){
    std::cin>>walrus[i].a;
    walrus[i].i=N-1-i;
  }
  std::sort(walrus,walrus+N,agecmp);
  int front=1e9;
  for(int i=0;i<N;i++){
    if(walrus[i].i<front){
      walrus[i].d=-1;
      front=walrus[i].i;
    }else{
      walrus[i].d=walrus[i].i-front-1;
    }
  }
  std::sort(walrus,walrus+N,indexcmp);
  for(int i=0;i<N;i++){
    if(i>0){
      std::cout<<" ";
    }
    std::cout<<walrus[i].d;
  }
  std::cout<<std::endl;
  return 0;
}