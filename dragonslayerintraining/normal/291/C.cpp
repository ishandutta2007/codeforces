#include <cstdio>
#include <stdint.h>
#include <set>

uint32_t readaddr(){
  uint32_t b[4];
  scanf("%u.%u.%u.%u",&b[0],&b[1],&b[2],&b[3]);
  return (b[0]<<24)|(b[1]<<16)|(b[2]<<8)|b[3];
}

uint32_t addr[100000];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    addr[i]=readaddr();
  }
  int mask=0;
  for(int k=0;k<31;k++){
    mask|=(1<<(32-k-1));
    std::set<uint32_t> net;
    for(int i=0;i<N;i++){
      net.insert(addr[i]&mask);
    }
    if(net.size()==K){
      printf("%d.%d.%d.%d\n",(mask>>24)&0xff,(mask>>16)&0xff,(mask>>8)&0xff,mask&0xff);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}