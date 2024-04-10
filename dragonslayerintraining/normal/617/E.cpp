#include <cstdio>
#include <algorithm>
#include <vector>

const int BLOCK=400;

int cnt[1<<20];

int as[100005];

struct Query{
  int l,r,id;
  Query(int l,int r,int id):l(l),r(r),id(id){
  }
  bool operator<(Query q)const{
    if(l/BLOCK!=q.l/BLOCK) return l/BLOCK<q.l/BLOCK;
    if(r!=q.r) return (r<q.r)^((l/BLOCK)&1);
    return l<q.l;
  } 
};
std::vector<Query> qs;
long long ans[100005];
long long total=0;
int K;

void insert(int x){
  total+=cnt[x^K];
  cnt[x]++;
}

void erase(int x){
  cnt[x]--;
  total-=cnt[x^K];
}

int main(){
  int N,M;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    as[i]^=as[i-1];
  }
  for(int i=0;i<M;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    L--;
    qs.emplace_back(L,R,i);
  }
  std::sort(qs.begin(),qs.end());
  int l=0,r=-1;
  for(auto q:qs){
    while(q.l<l) insert(as[--l]);
    while(q.r>r) insert(as[++r]);
    while(q.l>l) erase(as[l++]);
    while(q.r<r) erase(as[r--]);
    ans[q.id]=total;
  }
  for(int i=0;i<M;i++){
    printf("%I64d\n",ans[i]);
  }
}