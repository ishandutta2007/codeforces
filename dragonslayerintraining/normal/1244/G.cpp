#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>

int ps[1000005];

std::set<int> unused;

int main(){
  int N;
  long long K;
  scanf("%d %I64d",&N,&K);
  long long excess=K-N*(N+1LL)/2;
  if(excess<0){
    printf("-1\n");
    return 0;
  }
  for(int i=1;i<=N;i++){
    unused.insert(i);
  }
  for(int i=1;i<=N;i++){
    if(excess>0){
      ps[i]=std::min<long long>(N+1-i,i+excess);
      excess-=(ps[i]-i);
      assert(unused.count(ps[i]));
      unused.erase(ps[i]);
    }else{
      ps[i]=*unused.begin();
      unused.erase(unused.begin());
    }
  }
  long long sum=0;
  for(int i=1;i<=N;i++){
    sum+=std::max(i,ps[i]);
  }
  printf("%I64d\n",sum);
  for(int i=1;i<=N;i++){
    printf("%d ",i);
  }
  printf("\n");
  for(int i=1;i<=N;i++){
    printf("%d ",ps[i]);
  }
  printf("\n");
}