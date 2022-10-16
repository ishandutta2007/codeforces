#include <cstdio>
#include <map>

const int MAXA=15000005;
int factor[MAXA];

int as[300005];

int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}

std::map<int,int> cnt;

int main(){
  for(int i=2;i<MAXA;i++){
    if(factor[i]==0){
      for(int k=i;k<MAXA;k+=i){
	factor[k]=i;
      }
    }
    //printf("factor[%d]=%d\n",i,factor[i]);
  }
  int N;
  scanf("%d",&N);
  int g=0;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    g=gcd(g,as[i]);
  }
  for(int i=0;i<N;i++){
    as[i]/=g;
    for(int prev=0;factor[as[i]];as[i]/=factor[as[i]]){
      int f=factor[as[i]];
      if(f==prev) continue;
      cnt[f]++;
      prev=f;
    }
  }
  int best=0;
  for(auto it:cnt){
    best=std::max(best,it.second);
  }
  printf("%d\n",best?(N-best):-1);
  return 0;
}