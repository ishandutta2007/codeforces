// Problem: A. Maximal Binary Matrix
// Contest: Codeforces - Educational Codeforces Round 20
// URL: https://codeforces.com/contest/803/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int a[1003][1003];
signed main()
{
	int n=read(),m=read();
	if(m>n*n)
	{
		puts("-1");
		return 0;
	}
	for(int i=1; i<=n; i++)
	for(int j=1; j<=n; j++) if(a[i][j]==0)
	{
		if(i==j)
		{
			if(m>=1) a[i][i]=1,--m;
		}
		else
		{
			if(m>=2) a[i][j]=a[j][i]=1,m-=2;
		}
	}
	for(int i=1; i<=n; i++,puts(""))
	for(int j=1; j<=n; j++)
	printf("%d ",a[i][j]);
    return 0;
}