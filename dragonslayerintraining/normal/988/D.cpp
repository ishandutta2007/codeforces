#include <cstdio>
#include <stdint.h>
#include <set>

std::set<int64_t> set;

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=0;i<N;i++){
    int64_t A;
    scanf("%I64d",&A);
    set.insert(A);
  }
  for(int64_t a:set){
    for(int64_t k=0;k<32;k++){
      if(set.count(a-(1LL<<k))&&set.count(a+(1LL<<k))){
	printf("3\n%I64d %I64d %I64d\n",a-(1LL<<k),a,a+(1LL<<k));
	return 0;
      }
    }
  }
  
  for(int64_t a:set){
    for(int64_t k=0;k<32;k++){
      if(set.count(a-(1LL<<k))){
	printf("2\n%I64d %I64d\n",a-(1LL<<k),a);
	return 0;
      }
    }
  }
  printf("1\n%I64d\n",*set.begin());
  return 0;
}