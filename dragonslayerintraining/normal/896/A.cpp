#include <cstdio>
#include <cassert>
#include <cstring>
#include <stdint.h>
#include <algorithm>

char base[]="What are you doing at the end of the world? Are you busy? Will you save us?";
int64_t base_len=strlen(base);

char seg1[]="What are you doing while sending \"";
int64_t seg1_len=strlen(seg1);
char seg2[]="\"? Are you busy? Will you send \"";
int64_t seg2_len=strlen(seg2);
char seg3[]="\"?";
int64_t seg3_len=strlen(seg3);

int64_t len[100001];

char answer(int64_t N,int64_t K){
  if(K>=len[N]){
    return '.';
  }
  for(;N>0;N--){
    if(K<seg1_len){
      return seg1[K];
    }
    K-=seg1_len;
    if(K<len[N-1]){
      continue;
    }
    K-=len[N-1];
    if(K<seg2_len){
      return seg2[K];
    }
    K-=seg2_len;
    if(K<len[N-1]){
      continue;
    }
    K-=len[N-1];
    if(K<seg3_len){
      return seg3[K];
    }
    K-=seg3_len;
    assert(false);
  }
  assert(K<base_len);
  return base[K];
}

int main(){
  len[0]=base_len;
  for(int64_t i=1;i<=100000;i++){
    len[i]=std::min<int64_t>(1e18,len[i-1]*2+seg1_len+seg2_len+seg3_len);
  }
  int64_t Q;
  scanf("%I64d",&Q);
  while(Q-->0){
    int64_t N,K;
    scanf("%I64d %I64d",&N,&K);
    K--;
    printf("%c",answer(N,K));
  }
  printf("\n");
  return 0;
}