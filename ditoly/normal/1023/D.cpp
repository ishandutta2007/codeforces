#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
#define N 262144
int a[MN+5],l[MN+5],t[N*2+5];
int query(int l,int r)
{
	int res=t[0];
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)res=min(res,t[l+1]);
		if( r&1)res=min(res,t[r-1]);
	}
	return res;
}
int main()
{
	int n,q,i,x=0,s=0;
	n=read();q=read();
	for(i=1;i<=n;++i)a[i]=read(),x+=!a[i],s+=a[i]==q;
	if(x==n)for(i=1;i<=n;++i)a[i]=q;
	else
	{
		for(x=0,i=1;i<=n;++i)if(a[i])x=a[i];else a[i]=s?x:(++s,q);
		for(x=0,i=n;i;--i)if(a[i])x=a[i];else a[i]=s?x:(++s,q);
	}
	memset(t,40,sizeof(t));
	for(i=1;i<=n;++i)t[i+N]=a[i];
	for(i=N;--i;)t[i]=min(t[i<<1],t[i<<1|1]);
	for(i=1;i<=n;++i)if(l[a[i]]&&query(l[a[i]],i)<a[i])return 0*puts("NO");else l[a[i]]=i;
	for(i=1;i<=n;++i)if(a[i]==q)break;
	if(i>n)return 0*puts("NO");
	puts("YES");
	for(i=1;i<=n;++i)printf("%d ",a[i]);
}