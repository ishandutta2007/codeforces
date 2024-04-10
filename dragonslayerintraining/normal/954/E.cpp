#include <cstdio>
#include <algorithm>
#include <stdint.h>

struct Water{
  int64_t a,t;
  bool operator<(struct Water other)const{
    return t<other.t;
  }
}ws[200000];

int main(){
  int64_t N,T;
  scanf("%I64d %I64d",&N,&T);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&ws[i].a);
  }
  int64_t sum=0;
  double qt=0;
  for(int64_t i=0;i<N;i++){
    scanf("%I64d",&ws[i].t);
    
    ws[i].t-=T;
    
    sum+=ws[i].a*ws[i].t;
    qt+=ws[i].a;
  }
  if(sum>0){
    for(int64_t i=0;i<N;i++){
      ws[i].t*=-1;
    }
    sum*=-1;
  }
  std::sort(ws,ws+N);
  for(int64_t i=0;i<N&&sum;i++){
    if(sum>=ws[i].a*ws[i].t){
      double amount=double(sum)/ws[i].t;
      sum=0;
      qt-=amount;
    }else{
      sum-=ws[i].a*ws[i].t;
      qt-=ws[i].a;
    }
  }
  printf("%.10lf\n",qt);
  return 0;
}