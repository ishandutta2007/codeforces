#include <cstdio>
#include <algorithm>

int as[500005];
int freq[500005];
int first[500005];
int last[500005];
int whole[500005];
int frac[500005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&as[i]);
    last[as[i]]=i;
    if(!first[as[i]]) first[as[i]]=i;
    freq[as[i]]++;
  }
  for(int i=1;i<=N;i++){
    whole[i]=whole[i-1];
    if(last[as[i]]==i){
      whole[i]=std::max(whole[i-1],whole[first[as[i]]-1]+freq[as[i]]);
    }
  }
  int best=0;
  for(int i=1;i<=N;i++){
    frac[as[i]]=std::max(frac[as[i]],whole[i-1])+1;
    best=std::max(best,frac[as[i]]);
  }
  printf("%d\n",N-best);
}