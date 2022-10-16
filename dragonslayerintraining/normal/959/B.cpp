#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <stdint.h>

char words[100000][25];

int cost[100000];
int group[100000];

int groupcost[100000];

int main(){
  int N,K,M;
  scanf("%d %d %d",&N,&K,&M);
  for(int i=0;i<N;i++){
    scanf("%s",words[i]);
  }
  for(int i=0;i<N;i++){
    scanf("%d",&cost[i]);
  }
  for(int k=0;k<K;k++){
    int X;
    scanf("%d",&X);
    for(int i=0;i<X;i++){
      int I;
      scanf("%d",&I);
      I--;
      group[I]=k;
    }
    groupcost[k]=1e9;
  }
  for(int i=0;i<N;i++){
    groupcost[group[i]]=std::min(groupcost[group[i]],cost[i]);
  }
  std::map<std::string,int> wordcost;
  for(int i=0;i<N;i++){
    wordcost[std::string(words[i])]=groupcost[group[i]];
  }
  char msg[25];
  int64_t total=0;
  for(int i=0;i<M;i++){
    scanf("%s",msg);
    total+=wordcost[std::string(msg)];
  }
  printf("%I64d\n",total);
  
  return 0;
}