#include <cstdio>
#include <vector>
#include <algorithm>

int bs[100005];

int main(){
  int N,M,K;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&bs[i]);
  }
  std::vector<int> good;
  for(int i=0;i<N-1;i++){
    good.push_back(bs[i+1]-bs[i]-1);
  }
  std::sort(good.begin(),good.end());
  std::reverse(good.begin(),good.end());
  int ans=bs[N-1]-bs[0]+1;
  for(int i=0;i<K-1&&i<good.size();i++){
    ans-=good[i];
  }
  printf("%d\n",ans);
  return 0;
}