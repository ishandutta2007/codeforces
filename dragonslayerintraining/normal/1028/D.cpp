#include <cstdio>
#include <cstring>
#include <set>
#include <cstdlib>
#include <stdint.h>
#include <algorithm>

const int64_t INF=1e9+7;
const int64_t MOD=1e9+7;

char str[32];

std::set<int> have;
int buy=0,sell=INF;

void fail(){
  printf("0\n");
  exit(0);
}

int main(){
  int N;
  scanf("%d",&N);
  int64_t cnt=1;
  for(int i=0;i<N;i++){
    int X;
    scanf("%s %d",str,&X);
    if(!strcmp(str,"ADD")){
      have.insert(X);
    }else{
      auto it=have.find(X);
      if(*it>buy&&*it<sell){
	cnt=cnt*2%MOD;
      }
      if(*it==buy) buy=0;
      if(*it==sell) sell=INF;
      if(it!=have.begin()){
	if(*std::prev(it)>=buy){
	  buy=*std::prev(it);
	}else{
	  fail();
	}
      }
      if(std::next(it)!=have.end()){
	if(*std::next(it)<=sell){
	  sell=*std::next(it);
	}else{
	  fail();
	}
      }
      have.erase(it);
    }
    if(buy>=sell) fail();
    //printf("I=%d buy=%d sell=%d\n",i,buy,sell);
  }
  int amb=1;
  for(auto v:have){
    if(v>buy&&v<sell){
      amb++;
    }
  }
  printf("%d\n",(int)(amb*cnt%MOD));
  return 0;
}