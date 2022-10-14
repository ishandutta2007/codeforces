// Problem: C. Shawarma Tent
// Contest: Codeforces - Codeforces Round #608 (Div. 2)
// URL: https://codeforces.com/contest/1271/problem/C
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
int x[1000003],y[1000003];
signed main()
{
	int n=read(),sx=read(),sy=read();
	for(int i=1; i<=n; i++) x[i]=read(),y[i]=read();
	int A=0,B=0,C=0,D=0;
	for(int i=1; i<=n; i++)
	{
		if(x[i]<sx) ++A;
		if(x[i]>sx) ++B;
		if(y[i]<sy) ++C;
		if(y[i]>sy) ++D;
	}
	int ans=-1;
	int x,y;
	if(A>ans) x=sx-1,y=sy,ans=max(ans,A);
	if(B>ans) x=sx+1,y=sy,ans=max(ans,B);
	if(C>ans) x=sx,y=sy-1,ans=max(ans,C);
	if(D>ans) x=sx,y=sy+1,ans=max(ans,D);
	printf("%lld\n",ans);
	printf("%lld %lld\n",x,y);
    return 0;
}