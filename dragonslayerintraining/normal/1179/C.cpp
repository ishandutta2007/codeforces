#include <cstdio>
#include <vector>
#include <array>
#include <algorithm>
#include <cassert>


int as[300005];
int bs[300005];
std::vector<std::array<int,3> > sorted;
std::array<int,3> qs[300005];

struct Node{
  int close,open;
  Node():close(0),open(0){
  }
  Node(int close,int open):close(close),open(open){
  }
}st[3600005];
int N,M,Q;

struct Node combine(struct Node a,struct Node b){
  if(a.open>b.close){
    return Node(a.close,b.open+a.open-b.close);
  }else{
    return Node(a.close+b.close-a.open,b.open);
  }
}

void pull(int i){
  st[i]=combine(st[i<<1],st[i<<1|1]);
}

void update(int w,int L,int R,int i,struct Node v){
  if(i<L||i>=R) return;
  if(R-L==1){
    st[w]=v;
  }else{
    int M=(L+R)/2;
    update(w<<1,L,M,i,v);
    update(w<<1|1,M,R,i,v);
    pull(w);
  }
}

void update(int i,struct Node v){
  //printf("update[%d]=(%d,%d)\n",i,v.close,v.open);
  update(1,0,N+M+Q,i,v);
}

int query(int w,int L,int R,int k){
  if(st[w].open<k) return -1;
  if(R-L==1){
    assert(st[w].open==1);
    return L;
  }else{
    int M=(L+R)/2;
    if(st[w<<1|1].open>=k){
      return query(w<<1|1,M,R,k);
    }else{
      return query(w<<1,L,M,k+st[w<<1|1].close-st[w<<1|1].open);
    }
  }
}

int query(){
  return query(1,0,N+M+Q,1);
}

void dump(int w,int L,int R){
  if(R-L==1){
    printf("(%d,%d)(%d) ",st[w].close,st[w].open,sorted[L][0]);
  }else{
    int M=(L+R)/2;
    dump(w<<1,L,M);
    dump(w<<1|1,M,R);
  }
}

int compress(int v,int t,int i){
  return std::lower_bound(sorted.begin(),sorted.end(),std::array<int,3>{v,t,i})-sorted.begin();
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    sorted.push_back({as[i],0,i});
  }
  for(int i=0;i<M;i++){
    scanf("%d",&bs[i]);
    sorted.push_back({bs[i],1,i});
  }
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    scanf("%d %d %d",&qs[i][0],&qs[i][1],&qs[i][2]);
    qs[i][1]--;
    if(qs[i][0]==1){
      sorted.push_back({qs[i][2],0,qs[i][1]});
    }else{
      sorted.push_back({qs[i][2],1,qs[i][1]});
    }
  }
  std::sort(sorted.begin(),sorted.end());
  for(int i=0;i<N;i++){
    update(compress(as[i],0,i),Node(0,1));
  }
  for(int i=0;i<M;i++){
    update(compress(bs[i],1,i),Node(1,0));
  }
  for(int i=0;i<Q;i++){
    int index=qs[i][1];
    if(qs[i][0]==1){
      update(compress(as[index],0,index),Node(0,0));
      as[index]=qs[i][2];
      update(compress(as[index],0,index),Node(0,1));
    }else{
      update(compress(bs[index],1,index),Node(0,0));
      bs[index]=qs[i][2];
      update(compress(bs[index],1,index),Node(1,0));
    }
    //dump(1,0,N+M+Q);
    //printf("\n");
    int res=query();
    if(res==-1){
      printf("-1\n");
    }else{
      printf("%d\n",sorted[res][0]);
    }
  }
  return 0;
}