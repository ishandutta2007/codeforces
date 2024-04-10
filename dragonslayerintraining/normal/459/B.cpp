#include <cstdio>
#include <map>
#include <stdint.h>

std::map<int64_t,int64_t> cnt;

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    cnt[A]++;
  }
  if(cnt.size()==1){
    printf("0 %I64d\n",N*(N-1)/2);
    return 0;
  }
  printf("%I64d %I64d\n",cnt.rbegin()->first-cnt.begin()->first,
	 cnt.begin()->second*cnt.rbegin()->second);
  return 0;
}