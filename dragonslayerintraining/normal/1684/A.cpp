#include <cstdio>
#include <algorithm>

char str[16];

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%s",str);
    char best='9';
    int len=0;
    for(int i=0;str[i];i++){
      best=std::min(best,str[i]);
      len++;
    }
    printf("%c\n",(len==2)?str[1]:best);
  }
}