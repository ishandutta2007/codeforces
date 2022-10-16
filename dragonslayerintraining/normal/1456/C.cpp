#include <cstdio>
#include <algorithm>

int cs[500005];
long long suff[500005];
long long suff2[500005];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  K++;
  for(int i=0;i<N;i++){
    scanf("%d",&cs[i]);
  }
  std::sort(cs,cs+N);
  for(int i=N-1;i>=0;i--){
    suff[i]=cs[i]+suff[i+1];
    suff2[i]=suff[i+1]+suff2[i+1];
  }
  long long best=-(1LL<<60);
  long long score=0;
  for(int i=0;i<N;i++){
    score+=1LL*(i/K)*cs[i];
    best=std::max(best,score+1LL*(i/K+1)*suff[i+1]+suff2[i+1]);
  }
  printf("%lld\n",best);
}