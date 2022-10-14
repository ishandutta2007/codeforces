// Problem: E. Superhero Battle
// Contest: Codeforces - Codeforces Round #547 (Div. 3)
// URL: https://codeforces.com/contest/1141/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int a[1000003];
signed main()
{
	int m=read();
	int n=read();
	int g=0,c=0;
	for(int i=1; i<=n; i++)
	{
		a[i]=read();
		g+=a[i];
		if(m+g<=0)
		{
			printf("%lld\n",i);
			return 0;
		}
		c=min(c,g);
	}
	if(g>=0)
	{
		printf("-1\n");
		return 0;
	}
	int P=(m+c)/(-g);
	m+=g*P;
	int ans=n*P;
	g=0;
	for(int i=1; i<=n; i++)
	{
		g+=a[i];
		if(m+g<=0)
		{
			printf("%lld\n",ans+i);
			return 0;
		}
	}
	for(int i=1; i<=n; i++)
	{
		g+=a[i];
		if(m+g<=0)
		{
			printf("%lld\n",ans+n+i);
			return 0;
		}
	}
    return 0;
}