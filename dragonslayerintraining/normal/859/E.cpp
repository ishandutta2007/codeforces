#include <cstdio>
#include <algorithm>
#include <stack>
#include <stdint.h>

const int64_t MOD=1e9+7;

int64_t next[200000];
int64_t head[200000];
int64_t trees[200000];

enum Status{
  TO_CYCLE,
  TO_VOID,
  VISITING,
  UNVISITED,
}status[200000];

int64_t N;

std::stack<int64_t> stk;

int64_t total=1;

void dfs(int64_t node){
  if(status[node]==VISITING){
    status[node]=TO_CYCLE;
    int64_t cycle_size=1;
    while(stk.top()!=node){
      stk.pop();
      cycle_size++;
    }
    stk.pop();
    //printf("CYCLE: %I64d\n",cycle_size);
    if(cycle_size>1){
      total=(total*2)%MOD;
    }
  }else if(status[node]==UNVISITED){
    status[node]=VISITING;
    stk.push(node);
    dfs(next[node]);
    if((!stk.empty())&&(stk.top()==node)){
      stk.pop();
    }
    switch((status[node]=status[next[node]])){
    case TO_VOID:head[node]=head[next[node]];break;
    }
  }
}

int main(){
  scanf("%I64d",&N);
  std::fill(status,status+2*N,TO_VOID);
  std::iota(head,head+2*N,0);
  for(int64_t i=0;i<N;i++){
    int64_t at,want;
    scanf("%I64d %I64d",&at,&want);
    at--,want--;
    next[at]=want;
    status[at]=UNVISITED;
  }
  for(int64_t i=0;i<2*N;i++){
    if(status[i]==UNVISITED){
      dfs(i);
    }
    /*
    printf("%I64d: ",i+1);
    switch(status[i]){
    case TO_VOID:printf("TO_VOID %I64d\n",head[i]+1);break;
    case TO_CYCLE:printf("TO_CYCLE\n");break;
    default:printf("ERROR\n");break;
    }
    */
  }
  for(int64_t i=0;i<2*N;i++){
    if(status[i]==TO_VOID){
      trees[head[i]]++;
    }
  }
  for(int64_t i=0;i<2*N;i++){
    if(trees[i]>1){
      //printf("TREE(%I64d): %I64d\n",i+1,trees[i]);
      total=(total*trees[i])%MOD;
    }
  }
  printf("%I64d\n",total);
  return 0;
}