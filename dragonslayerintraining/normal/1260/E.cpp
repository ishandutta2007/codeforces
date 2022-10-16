#include <cstdio>
#include <algorithm>
#include <set>

int as[1<<18];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  if(as[N-1]==-1){
    printf("0\n");
    return 0;
  }
  long long ans=as[N-1];
  std::multiset<long long> active;
  while(true){
    active.insert(as+N/2-1,as+N-1);
    if(*active.begin()==-1){
      printf("%lld\n",ans);
      return 0;
    }
    ans+=*active.begin();
    active.erase(active.begin());
    N/=2;
  }
}