#include <cstdio>
#include <algorithm>
#include <functional>

long long ps[200005];

long long gcd(long long a,long long b){
  return b?gcd(b,a%b):a;
}

void solve(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%I64d",&ps[i]);
  }
  std::sort(ps+1,ps+N+1,std::greater<long long>());
  for(int i=1;i<=N;i++){
    ps[i]/=100;
    ps[i]+=ps[i-1];
  }
  int X,A,Y,B;
  long long K;
  scanf("%d %d %d %d %I64d",&X,&A,&Y,&B,&K);
  if(X<Y){
    std::swap(X,Y);
    std::swap(A,B);
  }
  long long LAB=A/gcd(A,B)*B;
  int low=-1,high=N+1;
  while(high-low>1){
    int mid=(low+high)/2;
    int na=mid/A,nb=mid/B,nab=mid/LAB;
    na-=nab,nb-=nab;
    //printf("Take %d: %d AB %d A %d B\n",mid,nab,na,nb);
    long long score=ps[nab]*(X+Y)+(ps[nab+na]-ps[nab])*X+(ps[nab+nb+na]-ps[nab+na])*Y;
    //printf("score %I64d\n",score);
    if(score>=K){
      high=mid;
    }else{
      low=mid;
    }
  }
  printf("%d\n",high<=N?high:-1);
}

int main(){
  int Q;
  scanf("%d",&Q);
  while(Q--){
    solve();
  }
}