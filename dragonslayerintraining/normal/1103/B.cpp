#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

char str[64];

bool is_lt(int x,int y){
  printf("? %d %d\n",x,y);
  fflush(stdout);
  scanf("%s",str);
  if(!strcmp(str,"x")){
    return false;
  }else if(!strcmp(str,"y")){
    return true;
  }else{
    exit(0);
  }
}

bool is_le(int x,int y){
  return !is_lt(y,x);
}

void answer(int x){
  printf("! %d\n",x);
  fflush(stdout);
}

void play(){
  int low=1,high;//(low,high]
  while(is_le(low,low*2)){
    low*=2;
    if(low==2e9){
      answer(1);
      return;
    }
    low=std::min<int>(low,1e9);
  }
  high=low*2;
  while(high-low>1){
    int mid=(0LL+low+high)/2;
    if(is_lt(low,mid)){
      low=mid;
    }else{
      high=mid;
    }
  }
  answer(high);
}

int main(){
  for(scanf("%s",str);!strcmp(str,"start");scanf("%s",str)){
    play();
  }
  return 0;
}