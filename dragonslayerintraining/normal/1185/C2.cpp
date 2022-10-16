#include <cstdio>
#include <algorithm>

int ts[200005];
int cnt[101];


int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d",&ts[i]);
    int extra=M-ts[i];
    int fail=i;
    for(int t=1;t<=100;t++){
      int pass=std::min(cnt[t],extra/t);
      extra-=pass*t;
      fail-=pass;
    }
    printf("%d\n",fail);
    cnt[ts[i]]++;
  }
  return 0;
}