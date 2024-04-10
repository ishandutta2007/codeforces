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
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,K,pd[300001];
char s[300001];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read();
		int flag=0;
		memset(pd,-1,sizeof(pd));
		scanf("%s",s+1);
		for(int l=1;l<=n;l+=K)
		{
			for(int r=0;r<K && l+r<=n;++r)
			{
				if(s[l+r]=='0')
				{
					if(pd[r]==-1) pd[r]=0;
					else if(pd[r]==1) flag=1;
				}
				if(s[l+r]=='1')
				{
					if(pd[r]==-1) pd[r]=1;
					else if(pd[r]==0) flag=1;
				}
			}
		}
		if(flag)
		{
			puts("NO");
			continue;
		}
		int c0=0,c1=0;
		for(int i=0;i<K;++i)
		{
			if(pd[i]==0) ++c0;
			if(pd[i]==1) ++c1;
		}
		int C=abs(c0-c1);
		if(C<=K-c0-c1) puts("YES");
		else puts("NO");
	}
	return 0;
}