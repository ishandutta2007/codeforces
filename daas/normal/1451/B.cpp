#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,q,pre[110][2],suf[110][2];
char s[110];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),q=read();
		scanf("%s",s+1);
		memset(pre,0,sizeof(pre));
		memset(suf,0,sizeof(suf));
		for(int i=1;i<=n;++i)
		{
			pre[i][0]=pre[i-1][0];
			pre[i][1]=pre[i-1][1];
			if(s[i]=='0')
				pre[i][0]=1;
			else
				pre[i][1]=1;
		}
		for(int i=n;i>=1;--i)
		{
			suf[i][0]=suf[i+1][0];
			suf[i][1]=suf[i+1][1];
			if(s[i]=='0')
				suf[i][0]=1;
			else
				suf[i][1]=1;
		}
		while(q--)
		{
			int l=read(),r=read();
			if(pre[l-1][s[l]-'0'] || suf[r+1][s[r]-'0'])
				puts("YES");
			else
				puts("NO");
		}
	}
	return 0;
}