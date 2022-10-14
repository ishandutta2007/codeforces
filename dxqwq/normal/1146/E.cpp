// Problem: E. Hot is Cold
// Contest: Codeforces - Forethought Future Cup - Elimination Round
// URL: https://codeforces.com/contest/1146/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
// zhoukangyang 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
char op[200003];
char f[200003];
int v[200003];
void set0(int l,int r)
{
	for(int i=l; i<=r; ++i) f[i]=0;
}
void set1(int l,int r)
{
	for(int i=l; i<=r; ++i) f[i]=1;
}
void rev(int l,int r)
{
	for(int i=l; i<=r; ++i) f[i]^=1;
}
int a[200003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=m; ++i)
	{
		op[i]=getchar();
		while(op[i]!='<'&&op[i]!='>') op[i]=getchar();
		v[i]=read();
	}
#define R 200001
#define D 100001
	set1(D,R);
	for(int i=1; i<=m; ++i)
	{
		if(op[i]=='<')
		{
			int x=v[i]-1;
			if(x<=0)
			{
				set1(1,x+D),
				set1(-x+D,R);
			}
			else 
			{
				set1(1,-x+D-1),
				rev (-x+D,x+D),
				set1(x+D+1,R);
			}
		}
		else
		{
			int x=v[i]+1;
			if(x>=0)
			{
				set0(1,-x+D),
				set0(x+D,R);
			}
			else 
			{
				set0(1,x+D-1),
				rev (x+D,-x+D),
				set0(-x+D+1,R);
			}
		}
			// for(int i=1; i<=n; ++i) if(f[a[i]+D]) printf("%d ",abs(a[i]));
	// else printf("%d ",-abs(a[i]));
	// puts("");
	}
	for(int i=1; i<=n; ++i) if(f[a[i]+D]) printf("%d ",abs(a[i]));
	else printf("%d ",-abs(a[i]));
    return 0;
}