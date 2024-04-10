#include <cstdio>
#include <map>
#include <stdint.h>

char str[1000005];

int read_string(){
  scanf("%s",str);
  int res=0;
  for(int i=0;str[i];i++){
    res^=(1<<(str[i]-'a'));
  }
  return res;
}

std::map<int,int> cnt;

int main(){
  int N;
  scanf("%d",&N);
  int64_t ans=0;
  for(int i=0;i<N;i++){
    int s=read_string();
    ans+=cnt[s];
    for(int c=0;c<26;c++){
      if(cnt.count(s^(1<<c))){
	ans+=cnt[s^(1<<c)];
      }
    }
    cnt[s]++;
  }
  printf("%I64d\n",ans);
  return 0;
}