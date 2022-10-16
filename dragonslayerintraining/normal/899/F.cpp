#include <cstdio>
#include <stdint.h>
#include <vector>
#include <string>
#include <cassert>

int64_t to_mask(char c){
  if((c>='a')&&(c<='z')){
    return (1LL<<(c-'a'));
  }else if((c>='A')&&(c<='Z')){
    return (1LL<<((c-'A')+26));
  }else{
    return (1LL<<((c-'0')+52));
  }
}
char un_mask(int64_t mask){
  for(int i=0;i<26;i++){
    if(mask==to_mask('a'+i)){
      return 'a'+i;
    }
    if(mask==to_mask('A'+i)){
      return 'A'+i;
    }
  }
  for(int i=0;i<10;i++){
    if(mask==to_mask('0'+i)){
      return '0'+i;
    }
  }
  return 0;
}

std::string str;

struct Elem{
  int64_t has;
  int size;
}st[800000];

void build(int w,int L,int R){
  if(R-L==1){
    st[w].has=to_mask(str[L]);
    st[w].size=1;
  }else{
    int M=(L+R)/2;
    build(w*2+1,L,M);
    build(w*2+2,M,R);
    st[w].size=st[w*2+1].size+st[w*2+2].size;
    st[w].has=(st[w*2+1].has|st[w*2+2].has);
  }
  assert(st[w].size==R-L);
}

void update(int w,int a,int b,char c){
  if((st[w].has&to_mask(c))==0){
    return;
  }
  a=std::max(a,0);
  b=std::min(b,st[w].size);
  if(a>=b){
    return;
  }
  if(st[w].size==1){
    //Must be c to reach this
    st[w].has=0;
    st[w].size=0;
    return;
  }
  update(w*2+2,a-st[w*2+1].size,b-st[w*2+1].size,c);
  update(w*2+1,a,b,c);
  st[w].size=st[w*2+1].size+st[w*2+2].size;
  st[w].has=st[w*2+1].has|st[w*2+2].has;
}

void recover(int w){
  if(st[w].size==0){
    return;
  }else if(st[w].size==1){
    str+=un_mask(st[w].has);
  }else{
    recover(w*2+1);
    recover(w*2+2);
  }
}

char S[200005];

int main(){
  int N,M;
  scanf("%d %d %s",&N,&M,S);
  str=S;
  build(0,0,N);
  while(M-->0){
    int L,R;
    char C;
    scanf("%d %d %c",&L,&R,&C);
    L--;
    update(0,L,R,C);
  }
  str.clear();
  recover(0);
  printf("%s\n",str.c_str());
  return 0;
}