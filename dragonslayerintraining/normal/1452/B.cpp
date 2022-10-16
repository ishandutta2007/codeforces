#include <cstdio>
#include <algorithm>
#include <numeric>

int as[100005];

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
      scanf("%d",&as[i]);
    }
    long long total=std::accumulate(as,as+N,0LL);
    long long max=*std::max_element(as,as+N);
    long long need=std::max((total+N-2)/(N-1),max)*(N-1);
    printf("%lld\n",need-total);
  }
}