#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <stdint.h>

int M;

int64_t adj[40];

int64_t inhibit[1<<20];
int pop[1<<20];
int most[1<<20];

void connect(int64_t mask){
  for(int i=0;i<M;i++){
    if(mask&(1LL<<i)){
      adj[i]|=(mask&~(1LL<<i));
    }
  }
}

char name[64];
std::map<std::string,int> ids;

int get_ID(){
  std::string str(name);
  if(!ids.count(str)){
    int id=ids.size();
    ids[str]=id;
  }
  return ids[str];
}

void read_input(){
  int N;
  scanf("%d %d",&N,&M);
  int64_t mask=0;
  while(N-->0){
    int T;
    scanf("%d",&T);
    if(T==1){
      connect(mask);
      mask=0;
    }else{
      scanf("%s",name);
      mask|=(1LL<<get_ID());
    }
  }
  connect(mask);
}

int main(){
  read_input();
  int half=M-M/2;
  inhibit[0]=0;
  for(int k=0;k<half;k++){
    for(int i=0;i<(1<<k);i++){
      inhibit[i|(1<<k)]=inhibit[i]|adj[k];
      pop[i|(1<<k)]=pop[i]+1;
    }
  }
  for(int i=0;i<(1<<half);i++){
    if((i&inhibit[i])==0){
      int& x=most[inhibit[i]>>half];
      x=std::max(x,pop[i]);
    }
  }
  for(int k=0;k<(M-half);k++){
    for(int i=0;i<(1<<(M-half));i++){
      int& x=most[i|(1<<k)];
      x=std::max(x,most[i]);
    }
  }
  inhibit[0]=0;
  for(int k=0;k<(M-half);k++){
    for(int i=0;i<(1<<k);i++){
      inhibit[i|(1<<k)]=inhibit[i]|adj[k+half];
    }
  }
  int best=0;
  for(int i=0;i<(1<<(M-half));i++){
    if((i&(inhibit[i]>>half))==0){
      best=std::max(best,most[(1<<(M-half))-1-i]+pop[i]);
    }
  }
  printf("%d\n",best);
  return 0;
}