#include <cstdio>
#include <algorithm>
#include <stdint.h>

char S[1000005],T[1000005];
int64_t S_cnt[26];
int64_t wildcard;
int64_t T_cnt[26];

int main(){
  scanf("%s %s",S,T);
  for(int64_t i=0;S[i];i++){
    if(S[i]=='?'){
      wildcard++;
    }else{
      S_cnt[S[i]-'a']++;
    }
  }
  for(int64_t i=0;T[i];i++){
    T_cnt[T[i]-'a']++;
  }
  int64_t low=0,high=1000001;
  while(high-low>1){
    int64_t mid=(low+high)/2;
    int64_t budget=wildcard;
    for(int64_t i=0;i<26;i++){
      budget+=std::min<int64_t>(0,S_cnt[i]-T_cnt[i]*mid);
    }
    if(budget<0){
      high=mid;
    }else{
      low=mid;
    }
  }
  for(int64_t i=0;i<26;i++){
    int64_t D=T_cnt[i]*low-S_cnt[i];
    for(int64_t k=0;S[k];k++){
      if(D<=0){
	break;
      }
      if(S[k]=='?'){
	S[k]='a'+i;
	D--;
      }
    }
  }
  for(int64_t k=0;S[k];k++){
    if(S[k]=='?'){
      S[k]='a';
    }
  }
  printf("%s\n",S);
  return 0;
}