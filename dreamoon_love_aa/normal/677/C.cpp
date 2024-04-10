#include<cstdio>
char s[1000100];
main(){
  scanf("%s",s);
  long long an=1,x;
  for(int i=0;s[i];i++){
    if(s[i]>='0'&&s[i]<='9')x=s[i]-'0';
    if(s[i]>='A'&&s[i]<='Z')x=s[i]-'A'+10;
    if(s[i]>='a'&&s[i]<='z')x=s[i]-'a'+36;
    if(s[i]>='-'&&s[i]<='-')x=62;
    if(s[i]>='_'&&s[i]<='_')x=63;
    for(int j=0;j<6;j++){
      an*=3-x%2*2;
      an%=1000000007;
      x/=2;
    }
  }
  printf("%I64d",an);
}