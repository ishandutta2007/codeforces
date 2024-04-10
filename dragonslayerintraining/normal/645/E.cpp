#include <cstdio>
#include <cstring>
#include <algorithm>

const int MOD=1e9+7;

int N,K;
int ext[26];

int addmod(int& x,int y){
  x=(x+y)%MOD;
}

void add(int c){
  for(int i=0;i<K;i++){
    if(i!=c){
      addmod(ext[i],ext[c]);
    }
  }
}

char str[1000005];

std::pair<int,int> recent[26];

int modexp(int base,int exp){
  int ac=1;
  for(;exp>0;exp>>=1){
    if(exp&1){
      ac=1LL*ac*base%MOD;
    }
    base=1LL*base*base%MOD;
  }
  return ac;
}

int main(){
  scanf("%d %d",&N,&K);
  scanf("%s",str);
  if(K==1){
    printf("%d\n",int(strlen(str)+N+1));
    return 0;
  }
  for(int c=0;c<K;c++){
    ext[c]=1;
    recent[c].first=-1;
    recent[c].second=c;
  }
  for(int i=0;str[i];i++){
    add(str[i]-'a');
    recent[str[i]-'a'].first=i;
  }
  std::sort(recent,recent+K);
  for(int i=0;i<N;i++){
    add(recent[i%K].second);
  }
  int ans=MOD-1;
  for(int c=0;c<K;c++){
    addmod(ans,ext[c]);
  }
  printf("%d\n",(int)(1LL*ans*modexp(K-1,MOD-2)%MOD));
  return 0;
}