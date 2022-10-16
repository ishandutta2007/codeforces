#include <cstdio>
#include <stdint.h>

int last[100005];
int prefix[100005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    int A;
    scanf("%d",&A);
    prefix[i]=prefix[i-1]+!last[A];
    last[A]=i;
  }
  int64_t total=0;
  for(int i=1;i<=100000;i++){
    if(last[i]){
      total+=prefix[last[i]-1];
    }
  }
  printf("%I64d\n",total);
  return 0;
}