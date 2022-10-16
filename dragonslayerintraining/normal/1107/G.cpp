#include <cstdio>
#include <algorithm>
#include <stdint.h>

const int64_t INF=1e18+7;

struct Node{
  int64_t sum,prefix,suffix;
  Node(int64_t sum):sum(sum),prefix(std::max<int64_t>(0,sum)),suffix(std::max<int64_t>(0,sum)){
  }
  Node():Node(0){
  }
}st[600005];
int64_t N;

struct Node combine(struct Node a,struct Node b){
  struct Node res;
  res.sum=a.sum+b.sum;
  res.prefix=std::max(a.prefix,a.sum+b.prefix);
  res.suffix=std::max(b.suffix,a.suffix+b.sum);
  return res;
}

int64_t cs[300005];
int64_t ds[300005];
int64_t ls[300005];
int64_t rs[300005];

int64_t best=0;

struct Node query(int64_t a,int64_t b){
  struct Node left,right;
  for(a+=N,b+=N;a<b;a>>=1,b>>=1){
    if(a&1) left=combine(left,st[a++]);
    if(b&1) right=combine(st[--b],right);
  }
  return combine(left,right);
}

int main(){
  int64_t A;
  scanf("%I64d %I64d",&N,&A);
  for(int64_t i=0;i<N;i++){
    scanf("%I64d %I64d",&ds[i],&cs[i]);
    st[i+N]=Node(A-cs[i]);
    best=std::max(best,A-cs[i]);
  }
  for(int64_t i=N-1;i>0;i--){
    ds[i]=(ds[i]-ds[i-1])*(ds[i]-ds[i-1]);
  }
  ds[0]=ds[N]=INF;
  for(int64_t i=N-1;i>0;i--){
    st[i]=combine(st[i<<1],st[i<<1|1]);
  }
  for(int64_t i=1;i<N;i++){
    ls[i]=i-1;
    while(ds[ls[i]]<=ds[i]){
      ls[i]=ls[ls[i]];
    }
  }
  for(int64_t i=N-1;i>0;i--){
    rs[i]=i+1;
    while(ds[rs[i]]<=ds[i]){
      rs[i]=rs[rs[i]];
    }
  }
  for(int64_t i=1;i<N;i++){
    best=std::max(best,query(ls[i],i).suffix+query(i,i+1).sum+query(i+1,rs[i]).prefix-ds[i]);
    //printf("[%I64d,%I64d,%I64d,%I64d)=%I64d+%I64d+%I64d+%I64d\n",ls[i],i,i+1,rs[i],query(ls[i],i).suffix,query(i,i+1).sum,query(i+1,rs[i]).prefix,ds[i]);
  }
  printf("%I64d\n",best);
  return 0;
}