// Problem: E. Train Hard, Win Easy
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: https://codeforces.com/contest/1043/problem/E
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
struct pii
{
	int fi,se,id;
};
pii a[1000003];
bool cmp(pii x,pii y)
{
	return (x.se-x.fi)<(y.se-y.fi);
}
bool cc(pii x,pii y)
{
	return x.id<y.id;
}
int ans[1000003];
int c[1000003];
int b[1000003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i) 
	a[i].fi=read(),a[i].se=read(),a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; ++i) b[i]=b[i-1]+a[i].se;
	for(int i=n; i>=1; --i) c[i]=c[i+1]+a[i].fi;
	for(int i=1; i<=n; ++i) ans[a[i].id]=b[i-1]+a[i].fi*(i-1)+c[i+1]+a[i].se*(n-i);
	sort(a+1,a+n+1,cc);
	for(int i=1; i<=m; ++i)
	{
		int A=read(),B=read();
		int C=min(a[A].fi+a[B].se,a[A].se+a[B].fi);
		ans[A]-=C,ans[B]-=C;
	}
	for(int i=1; i<=n; ++i) printf("%lld ",ans[i]);
    return 0;
}