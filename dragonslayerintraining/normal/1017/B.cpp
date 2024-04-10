#include <cstdio>
#include <stdint.h>

char as[100005];
char bs[100005];

int main(){
  int N;
  scanf("%d",&N);
  scanf("%s %s",as,bs);

  int64_t cnt[2]={0,0};
  int64_t total[2]={0,0};
  for(int i=0;i<N;i++){
    if(bs[i]=='1'){
      cnt[as[i]-'0']++;
    }
    total[as[i]-'0']++;
  }
  printf("%I64d\n",total[0]*total[1]-cnt[0]*cnt[1]);
  return 0;
}