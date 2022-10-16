#include <cstdio>
#include <algorithm>

int first[26];
int last[26];

int prefix[1000001];

char seq[1000006];

int main(){
  std::fill(first,first+26,1e9);
  int N,K;
  scanf("%d %d",&N,&K);
  scanf("%s",seq);
  for(int i=0;seq[i];i++){
    first[seq[i]-'A']=std::min(first[seq[i]-'A'],i);
    last[seq[i]-'A']=std::max(last[seq[i]-'A'],i);
  }
  for(int i=0;i<26;i++){
    if(first[i]<=last[i]){
      prefix[first[i]]++;
      prefix[last[i]+1]--;
    }
  }
  if(prefix[0]>K){
    printf("YES\n");
    return 0;
  }
  for(int i=0;seq[i];i++){
    prefix[i+1]+=prefix[i];
    if(prefix[i+1]>K){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}