// Problem: B. Cormen  The Best Friend Of a Man
// Contest: Codeforces - Codeforces Round #377 (Div. 2)
// URL: https://codeforces.com/contest/732/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int n=read(),m=read(),S=0;
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<n; i++)
	{
		if(a[i]+a[i+1]<m)
		{
			S+=m-a[i]-a[i+1];
			a[i+1]+=(m-a[i]-a[i+1]);
		}
	}
	printf("%lld\n",S);
	for(int i=1; i<=n; i++) printf("%lld ",a[i]);
	puts("");
    return 0;
}