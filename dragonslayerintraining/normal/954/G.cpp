#include <cstdio>
#include <queue>
#include <stdint.h>

int64_t delta[1000001];

int main(){
  int64_t N,R,K;
  scanf("%I64d %I64d %I64d",&N,&R,&K);
  for(int64_t i=0;i<N;i++){
    int64_t A;
    scanf("%I64d",&A);
    delta[std::max<int64_t>(0,i-R)]+=A;
    delta[std::min<int64_t>(N,i+R+1)]-=A;
  }
  int64_t low=0,high=2e18;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    int64_t curr=0;
    int64_t need=0;
    std::queue<std::pair<int64_t,int64_t> > rem;
    for(int64_t i=0;i<N;i++){
      curr+=delta[i];
      if(rem.size()&&i==rem.front().first){
	curr-=rem.front().second;
	rem.pop();
      }
      if(curr<mid){
	int64_t diff=mid-curr;
	rem.emplace(i+2*R+1,diff);
	curr+=diff;
	need+=diff;
	if(need>K){
	  break;
	}
      }
    }
    //printf("%I64d => %I64d\n",mid,need);
    if(need>K){
      high=mid;
    }else{
      low=mid;
    }
  }
  printf("%I64d\n",low);
  return 0;
}