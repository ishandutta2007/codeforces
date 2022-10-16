#include <cstdio>
#include <algorithm>

const int MOD=1000000007;

int N;

std::pair<std::pair<int,int>,bool> task[200005];

int ft[400005];

void update(int i,int v){
  for(;i<=N*2;i+=(i&-i)){
    ft[i]=(ft[i]+v)%MOD;
  }
}

int query(int i){
  int res=0;
  for(;i>0;i-=(i&-i)){
    res=(res+ft[i])%MOD;
  }
  return res;
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d",&task[i].first.first,&task[i].first.second);
  }
  int T;
  scanf("%d",&T);
  for(int i=0;i<T;i++){
    int S;
    scanf("%d",&S);
    task[S-1].second=true;
  }
  std::sort(task,task+N);
  int star=0;
  int cost=0;
  for(int i=N-1;i>=0;i--){
    int b=task[i].first.second;
    bool needed=task[i].second;
    int add=query(b)+1;
    update(b,add);
    if(needed||b<star){
      cost=(cost+add)%MOD;
      star=std::max(star,b);
    }
  }
  printf("%d\n",cost);
}