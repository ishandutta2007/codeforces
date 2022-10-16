#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
#include <map>

int ft[200005];
int N;

void update(int i,int v){
  for(i++;i>0;i-=(i&-i)){
    ft[i]+=v;
  }
}

int query(int i){
  int ac=0;
  for(i++;i<=N;i+=(i&-i)){
    ac+=ft[i];
  }
  return ac;
}

int main(){
  scanf("%d",&N);
  std::map<int,std::vector<int> > elems;
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    if(A) elems[-A].push_back(i);
  }
  int l=N,r=0;
  long long ans=0;
  for(const auto& layer:elems){
    const auto& vec=layer.second;
    //printf("layer %d: %d:%d\n",-layer.first,r,l);
    l=std::min(l,vec.front());
    r=std::max(r,vec.back()+1);
    for(int i:vec){
      update(i,1);
    }
    assert(l<=r);
    ans+=query(l)-query(r);
    //printf("+%d\n",query(l)-query(r));
    std::swap(l,r);
  }
  printf("%lld\n",ans);
}