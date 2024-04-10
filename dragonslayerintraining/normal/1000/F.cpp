#include <cstdio>
#include <vector>
#include <queue>

int as[500005];
int N;

int ans[500005];

std::vector<std::pair<int,int> > qs[500005];

int last[500005];
int prev[500005];
int next[500005];

int st[1000005];

void extend(int& v,int i){
  if(!v||next[i]>next[v]) v=i;
}

void cancel(int& v,int i){
  if(v==i) v=0;
}

void st_insert(int L,int R,int i){
  for(L+=N+1,R+=N+1;L<R;L>>=1,R>>=1){
    if(L&1) extend(st[L++],i);
    if(R&1) extend(st[--R],i);
  }
}

void st_erase(int L,int R,int i){
  for(L+=N+1,R+=N+1;L<R;L>>=1,R>>=1){
    if(L&1) cancel(st[L++],i);
    if(R&1) cancel(st[--R],i);
  }
}

int st_query(int I){
  for(I+=N;I>0;I>>=1){
    if(st[I]) return as[st[I]];
  }
  return 0;
}

int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    qs[R].emplace_back(L,i);
  }
  for(int i=1;i<=N;i++){
    prev[i]=last[as[i]];
    last[as[i]]=i;
  }
  std::fill(last,last+500005,N+1);
  for(int i=N;i>=1;i--){
    next[i]=last[as[i]];
    last[as[i]]=i;
  }
  for(int R=1;R<=N;R++){
    if(prev[R]){
      st_erase(prev[prev[R]],prev[R],prev[R]);
    }
    st_insert(prev[R],R,R);
    for(auto q:qs[R]){
      ans[q.second]=st_query(q.first);
    }
  }
  for(int i=0;i<Q;i++){
    printf("%d\n",ans[i]);
  }
  return 0;
}