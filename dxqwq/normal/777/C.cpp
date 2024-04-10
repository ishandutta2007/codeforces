#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s;
}
int a[100003],b[100003],c[100003];
int main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) a[i]=i;
	for(int i=1; i<=n; i++) for(int j=1,x; j<=m; j++)
	{
		x=read();
		if(x<c[j]) b[j]=i;
		c[j]=x,a[i]=min(a[i],b[j]);
	}
	for(int k=read(),l,r;k--;) l=read(),r=read(),puts(a[r]<=l?"Yes":"No");
	return 0;
}