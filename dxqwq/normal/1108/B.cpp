// Problem: B. Divisors of Two Integers
// Contest: Codeforces - Codeforces Round #535 (Div. 3)
// URL: https://codeforces.com/contest/1108/problem/B
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
int x=1,y=1;
bool vis[1000003];
int a[100003];
bool f[100003];
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	sort(a+1,a+n+1);
	printf("%lld ",a[n]);
	int g=1;
	for(int i=n; i>=1; i--) if(a[n]%a[i]==0)
	if(vis[a[i]]==0)
	{
		vis[a[i]]=1;
	} 
	else
	{
		g=g/__gcd(g,a[i])*a[i];
	}
	else g=g/__gcd(g,a[i])*a[i];
	printf("%lld ",g);
    return 0;
}