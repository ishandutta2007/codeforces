#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>

int N,X,Y;

int queryset(const std::vector<int>& set){
  if(set.empty()){
    return 0;
  }
  printf("? %d",static_cast<int>(set.size()));
  for(int v:set){
    printf(" %d",v+1);
  }
  printf("\n");
  fflush(stdout);//Is this really necessary?
  int res;
  scanf("%d",&res);
  if(res==-1){
    exit(0);
  }
  return res!=((set.size()%2)?X:0);
}

int querybit(int k){
  std::vector<int> set;
  for(int i=0;i<N;i++){
    if(i&(1<<k)){
      set.push_back(i);
    }
  }
  return queryset(set);
}

int querybits(int k1,int k2){
  std::vector<int> set;
  for(int i=0;i<N;i++){
    if((i&(1<<k1))&&(i&(1<<k2))){
      set.push_back(i);
    }
  }
  return queryset(set);
}

int main(){
  scanf("%d %d %d",&N,&X,&Y);
  int sum=0;
  for(int k=0;(1<<k)<=N;k++){
    sum|=(querybit(k)<<k);
  }
  int diffbit=-1;
  for(int k=0;(1<<k)<=N;k++){
    if((1<<k)&sum){
      diffbit=k;
      break;
    }
  }
  assert(diffbit!=-1);
  int first=(1<<diffbit);
  for(int k=0;(1<<k)<=N;k++){
    if(k!=diffbit){
      first|=(querybits(diffbit,k)<<k);
    }
  }
  int second=first^sum;
  if(first>second){
    std::swap(first,second);
  }
  printf("! %d %d\n",first+1,second+1);
  fflush(stdout);//Is this really necessary?
}