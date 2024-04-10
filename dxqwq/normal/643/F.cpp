// Problem: CF643F Bears and Juice
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF643F
// Memory Limit: 250 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
#include<bits/stdc++.h>
#define int unsigned
using namespace std;
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t) if(y&1u) res=res*t;
	return res; 
}
int A[1003],B[1003];
int C_[1003];
int C(int n,int m)
{
	if(C_[m]) return C_[m];
	for(int i=1,x=n; i<=m; ++i,--x) A[i]=x,B[i]=i;
	for(int i=1; i<=m; i++) for(int j=1; j<=m&&B[i]>1; j++) 
	{
		int t=__gcd(B[i],A[j]);
		B[i]/=t,A[j]/=t;
	}
	int s=1;
	for(int i=1; i<=m; i++) s*=A[i];
	return C_[m]=s;
}
signed main()
{
	unsigned ans=0;
	int n=read(),p=read(),q=read();
	for(int i=1; i<=q; ++i)
	{
		int g=0;
		for(int j=0; j<=p&&j<n; ++j) g+=qp(i,j)*C(n,j);
		ans^=g*i;
	}
	printf("%u\n",ans);
    return 0;
}