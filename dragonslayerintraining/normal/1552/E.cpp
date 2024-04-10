#include <cstdio>
#include <algorithm>

int N,K;

int last[101];
int prev[101*101];
int cs[101*101];
int cnt[100001];

int as[101];
int bs[101];

int main(){
  scanf("%d %d",&N,&K);
  for(int i=1;i<=N*K;i++){
    scanf("%d",&cs[i]);
    prev[i]=last[cs[i]];
    last[cs[i]]=i;
  }
  for(int i=1;i<=N*K;i++){
    if(!prev[i]) continue;
    if(bs[cs[i]]) continue;
    if(*std::max_element(cnt+prev[i],cnt+i+1)<((N+K-2)/(K-1))){
      as[cs[i]]=prev[i];
      bs[cs[i]]=i;
      for(int j=prev[i];j<=i;j++){
	cnt[j]++;
      }
    }
  }
  for(int i=1;i<=N;i++){
    printf("%d %d\n",as[i],bs[i]);
  }
}