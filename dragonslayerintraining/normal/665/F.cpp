//Algorithm from http://codeforces.com/blog/entry/44466?#comment-290036
#include <cstdio>
#include <algorithm>
#include <stdint.h>

int64_t small[317000],big[317000];

int main(){
  int64_t N;
  scanf("%I64d",&N);
  int64_t root=0;
  while(root*root<=N) root++;
  for(int64_t i=1;i<root;i++){
    small[i]=i-1;
    big[i]=N/i-1;
  }
  for(int64_t p=2;p<root;p++){
    if(small[p]==small[p-1]) continue;
    for(int64_t i=1;i<std::min(root,N/p/p+1);i++){
      big[i]=big[i]-((i*p<root)?big[i*p]:small[N/i/p])+small[p-1];
    }
    for(int64_t i=root-1;i>=p*p;i--){
      small[i]=small[i]-small[i/p]+small[p-1];
    }
  }
  int64_t cuberoot=1;
  while(cuberoot*cuberoot*cuberoot<=N) cuberoot++;
  int64_t ans=small[cuberoot-1];
  for(int64_t p=2;p*p<N;p++){
    if(small[p]==small[p-1]) continue;
    ans+=big[p]-small[p];
  }
  printf("%I64d\n",ans);
  return 0;
}