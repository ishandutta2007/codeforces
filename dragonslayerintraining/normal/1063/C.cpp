#include <cstdio>
#include <cstdlib>
#include <cstring>

int N;

bool query(int x,int y){
  printf("%d %d\n",x,y);
  fflush(stdout);
  char str[16];
  scanf("%s",str);
  return (!strcmp(str,"black"));
}

int main(){
  scanf("%d",&N);
  int hlow=0,hhigh=1e9;
  while(hhigh-hlow>1){
    int hmid=(hlow+hhigh)/2;
    if(query(hmid,1)){
      hlow=hmid;
    }else{
      hhigh=hmid;
    }
    if(--N==0){
      printf("%d %d %d %d\n",hlow,2,hhigh,0);
      return 0;
    }
  }
  int vlow=1,vhigh=1e9;
  while(vhigh-vlow>1){
    int vmid=(vlow+vhigh)/2;
    if(query(hlow,vmid)){
      vlow=vmid;
    }else{
      vhigh=vmid;
    }
    if(--N==0){
      printf("%d %d %d %d\n",hlow,(vlow+vhigh)/2,hhigh,0);
      return 0;
    }
  }
  return 0;
}