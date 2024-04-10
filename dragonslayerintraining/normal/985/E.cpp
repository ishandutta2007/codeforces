#include <cstdio>
#include <algorithm>

int as[500001];
int good[500001];
int cnt=0;

int main(){
  as[0]=-1e9;
  good[0]=true;
  int N,K,D;
  scanf("%d %d %d",&N,&K,&D);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
  }
  std::sort(as+1,as+N+1);
  int j=1;
  for(int i=K;i<=N;i++){
    while(as[i]-as[j]>D){
      cnt-=good[j-1];
      j++;
    }
    cnt+=good[i-K];
    good[i]=(cnt>0);
  }
  if(good[N]){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}