#include <cstdio>
#include <cassert>
#include <stdint.h>
#include <algorithm>

const int INF=1e9+7;

struct ST{
  int max{INF},max2{INF-1},max_cnt{0},max_lazy{INF};
  int min{-INF},min2{-INF+1},min_cnt{0},min_lazy{-INF};
  int64_t sum{0};
  void push(int w,int L,int R);
  void update(int w,int L,int R,int a,int b,int v);
  int64_t query(int w,int L,int R,int a,int b);
}st[400000];

void ST::push(int w,int L,int R){
  assert(max_lazy>max2);
  assert(min_lazy<min2);
  if(max_lazy<max){
    assert(max!=INF);
    sum-=(int64_t)max_cnt*max;
    max=max_lazy;
    sum+=(int64_t)max_cnt*max;
    if(R-L>1){
      st[w*2+1].max_lazy=std::min(st[w*2+1].max_lazy,max_lazy);
      st[w*2+2].max_lazy=std::min(st[w*2+2].max_lazy,max_lazy);
    }
  }
  if(min_lazy>min){
    assert(min!=-INF);
    sum+=(int64_t)min_cnt*min;
    min=min_lazy;
    sum-=(int64_t)min_cnt*min;
    if(R-L>1){
      st[w*2+1].min_lazy=std::max(st[w*2+1].min_lazy,min_lazy);
      st[w*2+2].min_lazy=std::max(st[w*2+2].min_lazy,min_lazy);
    }
  }
}

void ST::update(int w,int L,int R,int a,int b,int v){
  push(w,L,R);
  if((a>=R)||(b<=L)){
    return;
  }
  if((v>=max)||(v<=min)){
    return;
  }
  if(R-L==1){
    if(v>0){
      max=max_lazy=std::min(max,v),max2=0;
    }else{
      min=min_lazy=std::max(min,v),min2=0;
    }
    if((max<INF)&&(min>-INF)){
      sum=max-min;
      max_cnt=min_cnt=1;
    }else{
      assert(max_cnt==0);
      assert(min_cnt==0);
      sum=0;
    }
    return;
  }
  if((a<=L)&&(b>=R)&&
     (((v<max)&&(v>max2))||
      ((v>min)&&(v<min2)))){
    if(v>0){
      max_lazy=v;
    }else{
      min_lazy=v;
    }
    push(w,L,R);
  }else{
    int M=(L+R)/2;
    st[w*2+1].update(w*2+1,L,M,a,b,v);
    st[w*2+2].update(w*2+2,M,R,a,b,v);
    
    max=max_lazy=std::max(st[w*2+1].max,st[w*2+2].max);
    max_cnt=0;
    if(st[w*2+1].max==max){max_cnt+=st[w*2+1].max_cnt;}
    if(st[w*2+2].max==max){max_cnt+=st[w*2+2].max_cnt;}
    max2=0;
    for(int v:{st[w*2+1].max,st[w*2+1].max2,
	  st[w*2+2].max,st[w*2+2].max2}){
      if(v<max){
	max2=std::max(max2,v);
      }
    }
    
    min=min_lazy=std::min(st[w*2+1].min,st[w*2+2].min);
    min_cnt=0;
    if(st[w*2+1].min==min){min_cnt+=st[w*2+1].min_cnt;}
    if(st[w*2+2].min==min){min_cnt+=st[w*2+2].min_cnt;}
    min2=0;
    for(int v:{st[w*2+1].min,st[w*2+1].min2,
	  st[w*2+2].min,st[w*2+2].min2}){
      if(v>min){
	min2=std::min(min2,v);
      }
    }

    sum=st[w*2+1].sum+st[w*2+2].sum;
  }
}

int64_t ST::query(int w,int L,int R,int a,int b){
  push(w,L,R);
  if((a>=R)||(b<=L)){
    return 0;
  }
  if((a<=L)&&(b>=R)){
    return sum;
  }
  int M=(L+R)/2;
  return st[w*2+1].query(w*2+1,L,M,a,b)+st[w*2+2].query(w*2+2,M,R,a,b);
}

int main(){
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int T;
    scanf("%d",&T);
    if(T==1){
      int L,R,K;
      scanf("%d %d %d",&L,&R,&K);
      st[0].update(0,0,100000,L,R,K);
    }else{
      int L,R;
      scanf("%d %d",&L,&R);
      printf("%I64d\n",st[0].query(0,0,100000,L,R));
    }
  }
  return 0;
}