#include<cstdio>
int main()
{
	long long n=0,ans;
	char c;
	while((c=getchar())>='0'&&c<='9')n=n*10+c-'0';
	ans=--n/4*16;n%=4;if(n&1)ans+=7;
	if(c>='d'&&c<='f')ans+='g'-c;
	if(c>='a'&&c<='c')ans+=c-'a'+4;
	printf("%I64d",ans);
}