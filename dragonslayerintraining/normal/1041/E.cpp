#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

void fail(){
  printf("NO\n");
  exit(0);
}

int cnt[1005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    if(B!=N) fail();
    cnt[A]++;
  }
  std::vector<int> pool;
  std::vector<std::pair<int,int> > ans;
  for(int i=1;i<N;i++){
    pool.push_back(i);
    int head=N;
    if(pool.size()<cnt[i]) fail();
    for(int k=cnt[i];k>0;k--){
      ans.emplace_back(head,pool[pool.size()-k]);
      head=pool[pool.size()-k];
    }
    pool.resize(pool.size()-cnt[i]);
  }
  printf("YES\n");
  for(auto e:ans){
    printf("%d %d\n",e.first,e.second);
  }
  return 0;
}