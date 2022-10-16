#include <cstdio>
#include <vector>
#include <stdint.h>

int64_t P;

struct Func{
  std::vector<int64_t> crit;
  int64_t add;
  Func():crit(),add(0){
  }
  Func(int64_t c):crit({P}),add(c){
  }
  int64_t operator()(int64_t x){
    x+=add;
    int low=-1,high=crit.size();
    while(high-low>1){
      int mid=(low+high)/2;
      if(x-P*mid<crit[mid]){
	high=mid;
      }else{
	low=mid;
      }
    }
    return x-P*high;
  }
}st[4000005];

//f(g(x))
Func compose(Func f,Func g){
  int i=0,j=0;
  int64_t lazy=f.add;
  struct Func res;
  res.add=f.add+g.add;
  while(i<f.crit.size()||j<g.crit.size()){
    if(i==f.crit.size()){
      res.crit.push_back(g.crit[j++]+lazy);
    }else if(j==g.crit.size()){
      res.crit.push_back(f.crit[i++]);
      lazy-=P;
    }else if(f.crit[i]>g.crit[j]+lazy){
      res.crit.push_back(g.crit[j++]+lazy);
    }else if(f.crit[i]+P>=g.crit[j]+lazy){
      res.crit.push_back(f.crit[i]);
      j++;
    }else{
      res.crit.push_back(f.crit[i++]);
      lazy-=P;
    }
  }
  return res;
}

void build(int w,int L,int R){
  if(R-L==1){
    int A;
    scanf("%d",&A);
    st[w]=Func(A);
  }else{
    int M=(L+R)/2;
    build(w*2,L,M);
    build(w*2+1,M,R);
    st[w]=compose(st[w*2+1],st[w*2]);
  }
}

int64_t query(int w,int L,int R,int a,int b,int64_t x){
  if(a>=R||b<=L) return x;
  if(a<=L&&b>=R){
    return st[w](x);
  }
  int M=(L+R)/2;
  return query(w*2+1,M,R,a,b,query(w*2,L,M,a,b,x));
}

int main(){
  int N,Q;
  scanf("%d %d %I64d",&N,&Q,&P);
  build(1,0,N);
  while(Q--){
    int L,R;
    scanf("%d %d",&L,&R);
    L--;
    int init=0;
    printf("%I64d\n",query(1,0,N,L,R,init));
  }
}