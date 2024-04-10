#include <cstdio>
#include <map>
#include <cassert>

int as[100005];
int right[100005];
int left[100005];
int N,M;

void reach(int far[100005]){
  std::map<int,int> groups;//(pos-i,cnt)
  for(int i=1;i<=N;i++){
    groups[i]=1;
  }
  for(int i=1;i<=M+1;i++){
    auto bump=[&](int index){
      index-=i;
      if(groups.count(index)){
	groups[index-1]+=groups[index];
	groups.erase(index);
      }
    };
    bump(N+1);
    bump(as[i]);
    bump(0);
  }
  int index=0;
  for(auto it:groups){
    while(it.second--){
      far[++index]=it.first+(M+1);
    }
  }
  assert(index==N);
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=1;i<=M;i++){
    scanf("%d",&as[i]);
  }
  reach(right);
  for(int i=1;i<=M;i++){
    as[i]=N+1-as[i];
  }
  reach(left);
  long long ans=0;
  for(int i=1;i<=N;i++){
    ans+=std::max(0,right[i]-(N+1-left[N+1-i])+1);
  }
  printf("%I64d\n",ans);
}