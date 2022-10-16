#include <cstdio>
#include <algorithm>

char str[100005];

int cnt[256];

int main(){
  int N,K;
  scanf("%d %d %s",&N,&K,str);
  int extra=0;
  for(int i=0;str[i];i++){
    if(str[i]<'A'+K){
      cnt[str[i]]++;
    }else{
      extra++;
    }
  }
  int base=1e6;
  for(int i=0;i<K;i++){
    base=std::min(base,cnt['A'+i]);
  }
  printf("%d\n",base*K+extra);
  return 0;
}