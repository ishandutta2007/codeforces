#include <cstdio>
#include <algorithm>

int N,K;

int vs[1000005];
int best=1e9;

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    best=std::min(best,A);
    vs[std::max(0,A-K)]++;
    vs[A+1]--;
  }
  for(int i=1;i<=1000000;i++){
    vs[i]+=vs[i-1];
  }
  for(int gcd=K+1;gcd<=1000000;gcd++){
    int cnt=0;
    for(int k=gcd;k<=1000000;k+=gcd){
      cnt+=vs[k];
    }
    if(cnt==N){
      best=gcd;
    }
  }
  printf("%d\n",best);
  return 0;
}