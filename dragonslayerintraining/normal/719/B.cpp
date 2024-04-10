#include <cstdio>
#include <cstring>
#include <algorithm>

int N;
char str[100005];

int red[2];

int main(){
  scanf("%d %s",&N,str);
  for(int i=0;str[i];i++){
    red[i%2]+=(str[i]=='r');
  }
  printf("%d\n",std::min(std::max(red[0],N/2-red[1]),std::max(red[1],(N+1)/2-red[0])));
  return 0;
}