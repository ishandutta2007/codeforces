#include <cstdio>

int xs[100001];
int ys[100001];
int cnt[1000005];

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=1;i<=N;i++){
    scanf("%d",&xs[i]);
    xs[i]+=xs[i-1];
    cnt[xs[i]]++;
  }
  int ans=0;
  for(int i=1;i<=M;i++){
    scanf("%d",&ys[i]);
    ys[i]+=ys[i-1];
    if(cnt[ys[i]]){
      ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
}