// Problem: B. Minimum path
// Contest: Codeforces - Codeforces Round #517 (Div. 1, based on Technocup 2019 Elimination Round 2)
// URL: https://codeforces.com/contest/1071/problem/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
char s[2003][2003];
int a[2003][2003];
int mx[5003];
char ans[5003],cur[5003];
int tot;
bool f[2003][2003];
int n=read(),k=read();
void jpjsb()
{
	f[1][1]=1;
	printf("%c",s[1][1]);
	char c;
	for(int i=3; i<=2*n; i++) 
	{
		c='z'+1;
		for(int j=max(1,i-n); j<=min(n,i-1); j++)
		{
			int k=i-j;
			if((!f[j-1][k])&&(!f[j][k-1])) continue;
			c=min(c,s[j][k]);
		}	
		for(int j=max(1,i-n); j<=min(n,i-1); j++)
		{
			int k=i-j;
			if((!f[j-1][k])&&(!f[j][k-1])) continue;
			if(s[j][k]==c) f[j][k]=1;
		}	
		printf("%c",c);
	}
	return ;
}
signed main()
{
	for(int i=1; i<=n; i++) scanf("%s",s[i]+1);
    if(k==0)
    {
    	jpjsb();
    	return 0;
    }
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) a[i][j]=max(a[i-1][j],a[i][j-1])+(s[i][j]=='a');
	if(a[n][n]+k>=2*n-1)
	{
		for(int i=1; i<=2*n-1; i++) printf("a");
		puts("");
		return 0;
	}
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) mx[i+j]=max(mx[i+j],a[i][j]);
	int res=0;
	for(int i=2; i<=2*n; i++) if((i-1)-mx[i]<=k) res=i;
	tot=n*2-res-1;
	for(int i=1; i<res; i++) printf("a");
	char c='z'+1;
	for(int j=max(1,res+1-n); j<=min(n,res); j++)
	{
		int k=res+1-j;
		if(a[j-1][k]==mx[res]||a[j][k-1]==mx[res])c=min(c,s[j][k]);
	}
	for(int j=max(1,res+1-n); j<=min(n,res); j++)
	{
		int k=res+1-j;
		if(a[j-1][k]==mx[res]||a[j][k-1]==mx[res])if(s[j][k]==c) f[j][k]=1;
	}
	printf("%c",c);
	for(int i=res+2; i<=2*n; i++) 
	{
		c='z'+1;
		for(int j=max(1,i-n); j<=min(n,i-1); j++)
		{
			int k=i-j;
			if((!f[j-1][k])&&(!f[j][k-1])) continue;
			c=min(c,s[j][k]);
		}	
		for(int j=max(1,i-n); j<=min(n,i-1); j++)
		{
			int k=i-j;
			if((!f[j-1][k])&&(!f[j][k-1])) continue;
			if(s[j][k]==c) f[j][k]=1;
		}	
		printf("%c",c);
	}
	
	return 0;
}