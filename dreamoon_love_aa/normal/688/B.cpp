#include<cstdio>
char s[1000010];
main(){
  scanf("%s",s);
  int i;
  for(i=0;s[i];i++){
    printf("%c",s[i]);
  }
  for(i--;i>=0;i--)printf("%c",s[i]);
}