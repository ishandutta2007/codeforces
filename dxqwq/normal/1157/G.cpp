// Problem: CF1157G Inverse of Rows and Columns
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1157G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[203][203];
int b[203][203];
int ans1[203],ans2[203];
int n=read(),m=read();
void unputdownableakioi()
{
	puts("YES");
	for(int i=1; i<=n; ++i) printf("%d",ans1[i]);
	puts("");
	for(int i=1; i<=m; ++i) printf("%d",ans2[i]);
	puts("");
	exit(0);
	return ;
}
void cmll02akioi()
{
	puts("NO");
	exit(0);
	return ;
}
void check_the_fucking_1st_case()
{
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) b[i][j]=a[i][j];
	for(int j=1; j<=m; ++j) if(b[1][j])
	{
		ans2[j]=1;
		for(int i=1; i<=n; ++i) b[i][j]^=1;
	}
	bool F=1;
	for(int i=2; i<=n; ++i)
	{
		bool f0=0,f1=0;
		for(int j=1; j<=m; ++j) if(b[i][j]) f1=1; else f0=1;
		if(f0&&f1)
		{
			F=0;
			break;
		} 
		else if(f1) ans1[i]=1;
	}
	if(F) unputdownableakioi();
}
void check_the_fucking_2nd_case()
{
	for(int j=1; j<=m; ++j) if(b[1][j])
	{
		ans2[j]=1;
		for(int i=1; i<=n; ++i) b[i][j]^=1;
	}
	bool F=1;
	int sdt=n+1;
	for(int i=2; i<=n; ++i)
	{
		bool f0=0,f1=0;
		for(int j=1; j<=m; ++j) if(b[i][j]) f1=1; else f0=1;
		if(f0&&f1)
		{
			if(b[i][1]) 
			{
				ans1[i]=1;
				for(int j=1; j<=m; ++j) b[i][j]^=1;
				bool X=0;
				for(int j=1; j<=m; ++j) if(b[i][j]) X=1;
				else if(X) 
				{
					F=0;
					break;
				}
			}
			sdt=i+1;
			break;
		} 
		else if(f1) ans1[i]=1;
	}	
	if(!F) return ;
	for(int i=sdt; i<=n; ++i)
	{
		bool f0=0,f1=0;
		for(int j=1; j<=m; ++j) if(b[i][j]) f1=1; else f0=1;
		if(f0&&f1)
		{
			F=0;
			break;
		} 
		else if(f0) ans1[i]=1;
	}
	if(F) unputdownableakioi();
}
void check_the_fucking_3rd_case()
{
	for(int j=1; j<=m; ++j) if(!b[n][j])
	{
		ans2[j]=1;
		for(int i=1; i<=n; ++i) b[i][j]^=1;
	}
	bool F=1;
	int sdt=0;
	for(int i=n; i>=1; --i)
	{
		bool f0=0,f1=0;
		for(int j=1; j<=m; ++j) if(b[i][j]) f1=1; else f0=1;
		if(f0&&f1)
		{
			if(!b[i][m]) 
			{
				ans1[i]=1;
				for(int j=1; j<=m; ++j) b[i][j]^=1;
				bool X=0;
				for(int j=m; j>=1; --j) if(!b[i][j]) X=1;
				else if(X) 
				{
					F=0;
					break;
				}
			}
			sdt=i-1;
			break;
		} 
		else if(f0) ans1[i]=1;
	}	
	if(!F) return ;
	for(int i=sdt; i>=1; --i)
	{
		bool f0=0,f1=0;
		for(int j=1; j<=m; ++j) if(b[i][j]) f1=1; else f0=1;
		if(f0&&f1)
		{
			F=0;
			break;
		} 
		else if(f1) ans1[i]=1;
	}
	if(F) unputdownableakioi();
}
signed main()
{
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) a[i][j]=read();
	//0
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) b[i][j]=a[i][j];
	check_the_fucking_1st_case();
	//0
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) b[i][j]=a[i][j];
	for(int i=1; i<=n; ++i) ans1[i]=0;
	for(int i=1; i<=m; ++i) ans2[i]=0;
	check_the_fucking_2nd_case();
	//1
for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) b[i][j]=a[i][j];
	for(int i=1; i<=n; ++i) ans1[i]=0;
	for(int i=1; i<=m; ++i) ans2[i]=0;
	check_the_fucking_3rd_case();
	cmll02akioi();
	return 0;
}