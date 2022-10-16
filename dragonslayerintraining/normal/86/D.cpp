#include <cstdio>
#include <algorithm>
#include <vector>

const int BLOCK=300;

struct Query{
  int l,r;
  int id;
  Query(int l,int r,int id):l(l),r(r),id(id){
  }
  bool operator<(struct Query q)const{
    if(l/BLOCK!=q.l/BLOCK) return l/BLOCK<q.l/BLOCK;
    if(r!=q.r) return (r<q.r)^((q.l/BLOCK)&1);
    return l<q.l;
  }
};
std::vector<struct Query> queries;
int64_t ans[200005];

int as[200005];
int occ[2000005];
int64_t sum=0;

void change(int x,int delta){
  sum-=1LL*x*occ[x]*occ[x];
  occ[x]+=delta;
  sum+=1LL*x*occ[x]*occ[x];
}

int main(){
  int N,Q;
  scanf("%d %d",&N,&Q);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=0;i<Q;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    L--;
    queries.emplace_back(L,R,i);
  }
  std::sort(queries.begin(),queries.end());
  int l=0,r=0;
  //[l,r)
  for(auto q:queries){
    while(r<q.r) change(as[r++],1);
    while(l>q.l) change(as[--l],1);
    while(r>q.r) change(as[--r],-1);
    while(l<q.l) change(as[l++],-1);
    ans[q.id]=sum;
  }
  for(int i=0;i<Q;i++){
    printf("%I64d\n",ans[i]);
  }
  return 0;
}