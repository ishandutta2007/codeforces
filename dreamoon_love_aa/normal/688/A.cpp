#include<cstdio>
char s[111];
int n,d,an,now;
main(){
  scanf("%d%d",&n,&d);
  for(int i=0;i<d;i++){
    scanf("%s",s);
    for(int i=0;i<n;i++){
      if(s[i]=='0'){
        now++;
        if(an<now)an=now;
        break;
      }
      if(i==n-1)now=0;
    }
  }
  printf("%d",an);
}