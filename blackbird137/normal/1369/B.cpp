#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e5+5;
int t,n,flag,tot;
char s[N],ans[N];

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",s+1);flag=1;
		for(int i=0;i<=n;++i)
			if(s[i]<s[i-1])
				flag=0;
		if(flag)
		{
			printf("%s\n",s+1);
			continue;
		}
		tot=0;
		for(int i=1;i<=n;++i)
			if(s[i]=='0')
				ans[++tot]='0';
			else break;
		ans[++tot]='0';
		for(int i=n;i>=1;--i)
			if(s[i]=='1')
				ans[++tot]='1';
			else break;
		printf("%s\n",ans+1);
		for(int i=1;i<=tot;++i)
			ans[i]='\0';
	}
	return 0;
}