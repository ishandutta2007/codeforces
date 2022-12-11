#include<cstdio>
#define MAXN 200000
char s[MAXN+5];
int ans[MAXN+5],an;
int main()
{
	int n,a,b,k,i,f,l,c;
	scanf("%d%d%d%d%s",&n,&a,&b,&k,s);s[n]='1';
	for(i=l=c=0;i<=n;i++)if(s[i]=='1')c+=(i-l)/b,l=i+1;
	for(i=f=0;s[i];i++)
	{
		if(s[i]=='0')f++;
		if(s[i]=='1')f=0;
		if(f==b&&c>=a)ans[an++]=i+1,f=0,c--;
	}
	printf("%d\n",an);
	for(i=0;i<an;i++)printf("%d ",ans[i]);
}