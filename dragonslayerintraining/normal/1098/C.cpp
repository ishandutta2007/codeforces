#include <cstdio>
#include <stdint.h>
#include <vector>
#include <cstdlib>

int64_t deg[100005];
int64_t ps[100005];
int64_t hs[100005];
int64_t score=0;

void attach(int64_t node,int64_t parent){
  deg[parent]++;
  ps[node]=parent;
  hs[node]=hs[parent]+1;
  score+=hs[node];
}

//invalidates data
void detach(int64_t node){
  deg[ps[node]]--;
  score-=hs[node];
}

int64_t N,S;

bool check(int64_t branch){
  int64_t left=N;
  int64_t layer=1;
  int64_t height=1;
  int64_t score=0;
  while(left>0){
    layer=std::min(layer,left);
    score+=height*layer;
    //printf("%I64d at height %I64d\n",layer,height);
    left-=layer;
    layer*=branch;
    height++;
  }
  //printf("check(%I64d): %I64d\n",branch,score);
  return score<=S;
}

int main(){
  scanf("%I64d %I64d",&N,&S);
  int64_t low=0,high=N;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    if(check(mid)){
      high=mid;
    }else{
      low=mid;
    }
  }
  if(high==N){
    printf("No\n");
    exit(0);
  }
  int64_t branch=high;
  //fprintf(stderr,"Branch=%I64d\n",branch);
  hs[0]=1;
  score=1;
  std::vector<int64_t> prev;
  prev.push_back(0);
  for(int64_t last=1;last<N;){
    std::vector<int64_t> next;
    for(int64_t v:prev){
      for(int64_t j=0;j<branch;j++){
	if(last>=N) break;
	attach(last,v);
	next.push_back(last++);
      }
    }
    std::swap(prev,next);
  }
  //printf("init score: %I64d\n",score);
  int64_t spine=N-1;
  for(int64_t i=N-2;i>0;i--){
    if(deg[i]>0) continue;
    while(score+hs[spine]+1-hs[i]>S){
      spine=ps[spine];
    }
    if(deg[spine]==branch) break;
    //printf("Reattach %I64d to %I64d\n",i+1,spine+1);
    detach(i);
    attach(i,spine);
    spine=i;
  }
  if(score!=S){
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  for(int64_t i=1;i<N;i++){
    if(i>1) printf(" ");
    printf("%I64d",ps[i]+1);
  }
  printf("\n");
  return 0;
}