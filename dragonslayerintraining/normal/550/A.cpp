#include <cstdio>
#include <cstring>

char str[100000];
int len;

int main(){
  scanf("%s",str);
  len=strlen(str);
  bool ab=false,ba=false;
  for(int i=2;i<=len-2;i++){
    if((str[i-2]=='A')&&(str[i-1]=='B')){
      ab=true;
    }
    if((str[i-2]=='B')&&(str[i-1]=='A')){
      ba=true;
    }
    if(ab&&(str[i]=='B')&&(str[i+1]=='A')){
      printf("YES\n");
      return 0;
    }
    if(ba&&(str[i]=='A')&&(str[i+1]=='B')){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}