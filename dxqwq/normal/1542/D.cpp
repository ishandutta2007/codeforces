// Problem: D. Priority Queue
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
char op[1003];
int a[1003];
int s[503][503];
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i)
	{
	op[i]=getchar();
		while(op[i]!='+'&&op[i]!='-') op[i]=getchar();
		if(op[i]=='+') a[i]=read();
	}
	int ans=0;
	for(int i=1; i<=n; ++i)
	{
		if(op[i]=='-') continue;
		memset(s,0,sizeof(s));
		s[0][0]=1;
		for(int j=1; j<i; j++)
		{
			if(op[j]=='+')
			{
				if(a[j]<a[i]||(a[j]==a[i]&&j<i))
					{for(int k=0;k<=n;k++)
					{
						s[j][k]=s[j-1][k];
					if(k)s[j][k]=(s[j][k]+s[j-1][k-1])%p;
					}
					}else
					for(int k=0;k<=n;k++)
					s[j][k]=(s[j-1][k]<<1)%p;
			}
			else
			{
				s[j][0]=(s[j-1][0]+s[j-1][0])%p;	
				for(int k=1; k<=n; k++)
				s[j][k-1]=(s[j][k-1]+s[j-1][k])%p,
				s[j][k]=(s[j][k]+s[j-1][k])%p;
			}
		}
		for(int k=0; k<=n; k++) s[i][k]=s[i-1][k];
		for(int j=i+1; j<=n; j++)
		{
			if(op[j]=='+')
			{
				if(a[j]<a[i]||(a[j]==a[i]&&j<i))
					{for(int k=0;k<=n;k++)
					{
						s[j][k]=s[j-1][k];
					if(k)s[j][k]=(s[j][k]+s[j-1][k-1])%p;
					}}
					else
					for(int k=0;k<=n;k++)
					s[j][k]=(s[j-1][k]<<1)%p;
			}
			else
			{
				s[j][0]=s[j-1][0];	
				for(int k=1; k<=n; k++)
				s[j][k-1]=(s[j][k-1]+s[j-1][k])%p,
				s[j][k]=(s[j][k]+s[j-1][k])%p;
			}
		}
			for(int j=0; j<=n; j++) 
			ans=(ans+a[i]*s[n][j])%p;
	}
	printf("%lld\n",ans);
	return 0;
}