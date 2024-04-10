#include<cstdio>
int f[2018],j,m;char s[2018];
int main(){
scanf("%s",s);f[0]=1;
for(int i=0;s[i];i++)if(s[i]<48){
if((!i||s[i-1]<48)&&(s[i]==47||s[i]==42))return puts("0"),0;
for(j=++m;j;j--)f[j]=f[j-1];f[0]=0;
}else if(i&&s[i-1]<48)for(j=m;j;j--)f[j-1]=(f[j-1]+f[j])%1000003;
printf("%d",f[0]);
}