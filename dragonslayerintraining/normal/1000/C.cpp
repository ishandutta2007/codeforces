#include <cstdio>
#include <map>
#include <vector>
#include <stdint.h>

std::map<int64_t,int64_t> diff;

int64_t cnt[200005];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    int64_t L,R;
    scanf("%I64d %I64d",&L,&R);
    diff[L]++;
    diff[R+1]--;
  }
  std::vector<std::pair<int64_t,int64_t> > delta(diff.begin(),diff.end());
  int64_t lvl=0;
  for(int64_t i=0;i<delta.size()-1;i++){
    lvl+=delta[i].second;
    cnt[lvl]+=delta[i+1].first-delta[i].first;
  }
  for(int64_t i=1;i<=N;i++){
    if(i>1) printf(" ");
    printf("%I64d",cnt[i]);
  }
  printf("\n");
  return 0;
}