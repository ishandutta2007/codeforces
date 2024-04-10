#include <cstdio>
#include <algorithm>

int as[3005];

long long bs[3005];
int cs[3005];

int N,K;

long long rightward(int from,int to){
  return bs[to]-bs[from]+1LL*K*(cs[to]-cs[from]);
}
long long leftward(int from,int to){
  return -(bs[to]-bs[from]-1LL*K*(cs[to]-cs[from]));
}

int main(){
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    bs[i+1]=bs[i]+as[i];
    cs[i+1]=cs[i]+(as[i]==0);
  }
  if(rightward(0,N)<0||leftward(0,N)<0){
    printf("-1\n");
    return 0;
  }
  long long best=0;
  for(int i=0;i<=N;i++){
    for(int j=i+1;j<=N;j++){
      //0 -- i(max) -- j(min) -- 0
      best=std::max(best,std::min(rightward(0,i)+rightward(j,N),leftward(i,j)));
      //0 -- i(min) -- j(max) -- 0
      best=std::max(best,std::min(leftward(0,i)+leftward(j,N),rightward(i,j)));
    }
  }
  printf("%lld\n",best+1);
}