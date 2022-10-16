#include <iostream>
#include <algorithm>


int a[100005];

struct cquery{
  int l,r;
  int id;
  int res;
}queries[100005];

struct csqrtcmp{
  bool operator()(struct cquery a,struct cquery b)const{
    if(a.l/1000!=b.l/1000){
      return a.l/1000<b.l/1000;
    }
    if(a.r!=b.r){
      return a.r<b.r;
    }
    return a.l<b.l;
  }
}sqrtcmp;

struct cidcmp{
  bool operator()(struct cquery a,struct cquery b)const{
    return a.id<b.id;
  }
}idcmp;

int N,M;

int counts[1000005];
int total=0;

int main(){
  std::cin>>N>>M;
  for(int i=0;i<N;i++){
    std::cin>>a[i];
    if(a[i]>100000){
      a[i]=100001;
    }
  }
  for(int i=0;i<M;i++){
    int L,R;
    std::cin>>L>>R;
    queries[i].l=L-1;
    queries[i].r=R-1;
    queries[i].id=i;
  }
  std::sort(queries,queries+M,sqrtcmp);
  int L=0,R=-1;
  for(int i=0;i<M;i++){
    while(L<queries[i].l){
      if(counts[a[L]]==a[L]){
	total--;
      }
      counts[a[L]]--;
      if(counts[a[L]]==a[L]){
	total++;
      }
      L++;
    }
    while(L>queries[i].l){
      L--;
      if(counts[a[L]]==a[L]){
	total--;
      }
      counts[a[L]]++;
      if(counts[a[L]]==a[L]){
	total++;
      }
    }
    while(R>queries[i].r){
      if(counts[a[R]]==a[R]){
	total--;
      }
      counts[a[R]]--;
      if(counts[a[R]]==a[R]){
	total++;
      }
      R--;
    }
    while(R<queries[i].r){
      R++;
      if(counts[a[R]]==a[R]){
	total--;
      }
      counts[a[R]]++;
      if(counts[a[R]]==a[R]){
	total++;
      }
    }
    queries[i].res=total;
  }
  std::sort(queries,queries+M,idcmp);
  for(int i=0;i<M;i++){
    std::cout<<queries[i].res<<std::endl;
  }
  return 0;
}