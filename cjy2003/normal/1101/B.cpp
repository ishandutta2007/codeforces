#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[500050];
int n,l,r,ans;
bool flag,flag1;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='[')flag=1;
		if(s[i]==':'&&flag)
		{
			l=i;
			flag1=1;
			break;
		}
	}
	if(!flag1)
	{
		printf("-1");
		return 0;
	}
	flag=0;
	for(int i=n;i>=1;--i)
	{
		if(s[i]==']')flag=1;
		if(s[i]==':'&&flag)
		{
			r=i;
			break;
		}
	}
	if(l>=r)printf("-1");
	else
	{
		for(int i=l+1;i<r;++i)
			if(s[i]=='|')++ans;
		printf("%d",ans+4);
	}
	return 0;
}