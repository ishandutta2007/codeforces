// Problem: B. Multiplication Table
// Contest: Codeforces - Codeforces Round #586 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1220/problem/B
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
int a[1003][1003];
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++)
	a[i][j]=read();
	for(int i=1; i<=n; i++)
	{
		int x=i;
		//xy*xz/yz
		int p=x-1,q=x+1;
		if(x==1) p=x+2;
		if(x==n) q=x-2;
		int g=a[x][p]*a[x][q]/a[p][q];
		int t=sqrt(g);
		printf("%lld ",t);
	}
    return 0;
}