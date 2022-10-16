#include <cstdio>
#include <stdint.h>
#include <map>

int64_t as[100001];
int64_t bs[100001];

std::map<int64_t,int64_t> left,right;

int main(){
  int64_t N;
  scanf("%I64d",&N);
  for(int64_t i=1;i<=N;i++){
    scanf("%I64d",&as[i]);
    bs[i]=bs[i-1]+as[i];
    right[as[i]]++;
  }
  if(bs[N]%2==1){
    printf("NO\n");
    return 0;
  }
  for(int64_t i=0;i<=N;i++){
    int64_t val=(bs[i]*2-bs[N])/2;
    if(i>1&&left[val]){
      printf("YES\n");
      return 0;
    }
    if(i<N-1&&right[-val]){
      printf("YES\n");
      return 0;
    }
    if(i>0&&i<N&&val==0){
      printf("YES\n");
      return 0;
    }
    if(i==N) break;
    left[as[i+1]]++;
    right[as[i+1]]--;
  }
  printf("NO\n");
  return 0;
}