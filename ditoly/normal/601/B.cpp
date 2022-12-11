#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 100000
int a[MN+5],z[MN+5],zn,L[MN+5],R[MN+5],s[MN+5];
long long ans;
void dfs(int x)
{
	int ls=0,rs=0;s[x]=1;
	if(L[x])dfs(L[x]),s[x]+=ls=s[L[x]];
	if(R[x])dfs(R[x]),s[x]+=rs=s[R[x]];
	ans+=1LL*a[x]*(ls+1)*(rs+1);
}
int main()
{
	int n,q,l,r,i;
	n=read();q=read();
	for(i=1;i<=n;++i)a[i]=read();
	for(i=n;i>1;--i)a[i]=abs(a[i]-a[i-1]);
	while(q--)
	{
		l=read()+1;r=read();
		for(zn=0,i=l;i<=r;++i)
		{
			L[i]=R[i]=0;
			while(zn&&a[i]>a[z[zn]])L[i]=z[zn--];
			R[z[zn]]=i;z[++zn]=i;
		}
		ans=0;dfs(z[1]);
		printf("%I64d\n",ans);
	}
}