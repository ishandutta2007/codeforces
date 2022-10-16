#include <cstdio>
#include <algorithm>
#include <cmath>
#include <stdint.h>

const int64_t INF=1e15;

int64_t as[100001];

int64_t bs[400000];
int64_t cs[400000];

int64_t F;

void build(int64_t w,int64_t L,int64_t R,int64_t a,int64_t b){
  if(b<=L||a>=R) return;
  if(R-L==1){
    int64_t l=as[L];
    int64_t r=as[R];
    if(l<0&&r<0){
      bs[w]=0;
      cs[w]=2*-l;
    }else if(l<0){
      bs[w]=2*std::min(-l,r);
      cs[w]=2*(-l+r);
    }else if(r<0){
      bs[w]=0;
      cs[w]=0;
    }else{
      bs[w]=0;
      cs[w]=2*r;
    }
    //printf("[%I64d,%I64d]: %I64d %I64d %I64d %I64d\n",L,R,l,r,bs[w],cs[w]);
  }else{
    int64_t M=(L+R)/2;
    build(w*2+1,L,M,a,b);
    build(w*2+2,M,R,a,b);
    bs[w]=std::min(bs[w*2+1],bs[w*2+2]);
    cs[w]=std::min(cs[w*2+1],cs[w*2+2]);
  }
}

int64_t query_b(int64_t w,int64_t L,int64_t R,int64_t a,int64_t b){
  if(b<=L||a>=R) return INF;
  if(a<=L&&b>=R) return bs[w];
  int64_t M=(L+R)/2;
  return std::min(query_b(w*2+1,L,M,a,b),query_b(w*2+2,M,R,a,b));
}

int64_t query_c(int64_t w,int64_t L,int64_t R,int64_t a,int64_t b){
  if(b<=L||a>=R) return INF;
  if(a<=L&&b>=R) return cs[w];
  int64_t M=(L+R)/2;
  return std::min(query_c(w*2+1,L,M,a,b),query_c(w*2+2,M,R,a,b));
}

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&as[i]);
  }
  for(int64_t i=N-1;i>0;i--){
    as[i]-=as[i-1];
    F+=std::abs(as[i]);
  }
  as[0]=-INF;
  as[N]=INF;
  build(0,0,N,0,N);
  int64_t Q;
  scanf("%I64d",&Q);
  for(int64_t i=0;i<Q;i++){
    int64_t T,L,R,X;
    scanf("%I64d %I64d %I64d %I64d",&T,&L,&R,&X);
    if(T==1){
      printf("%I64d\n",F+std::max<int64_t>(-2*X,std::max(-query_b(0,0,N,L-1,R),2*X-query_c(0,0,N,L-1,R))));
    }else{
      F-=std::abs(as[L-1]);
      F-=std::abs(as[R]);
      as[L-1]+=X;
      as[R]-=X;
      F+=std::abs(as[L-1]);
      F+=std::abs(as[R]);
      build(0,0,N,L-2,L);
      build(0,0,N,R-1,R+1);
    }
  }
  return 0;
}