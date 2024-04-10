#include<cstdio>
#include<cstring>
int b[27],s;char c[1002];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	memset(b,0,sizeof b);s=0;
	scanf("%s",c);
	for(int i=0;c[i];i++)b[c[i]-96]++;
	for(int i=1;i<=26;i++)s+=b[i]>0;
	if(s<=1){puts("-1");continue;}
	for(int i=1;i<=26;i++)
	  for(;b[i]--;)putchar(i+96);
	puts("");
	}return 0;
}