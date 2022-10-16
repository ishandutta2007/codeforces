#include <cstdio>
#include <algorithm>

char str[105];

int main(){
  int N;
  scanf("%d %s",&N,str);
  int cnt=0;
  for(int i=0;str[i];i++){
    if(str[i]=='8') cnt++;
  }
  printf("%d\n",std::min(N/11,cnt));
  return 0;
}