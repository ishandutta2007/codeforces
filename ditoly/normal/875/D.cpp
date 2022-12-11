#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
int a[MN+5],z[MN+5],zn,l[MN+5],r[MN+5],ll[MN+5],rr[MN+5];
int lf[MN+5][30],rf[MN+5][30];
long long ans;
void dfs(int x)
{
	ll[x]=l[x]?(dfs(l[x]),ll[l[x]]):x;
	rr[x]=r[x]?(dfs(r[x]),rr[r[x]]):x;
	int L=ll[x]-1,R=rr[x]+1;
	for(int i=0;i<30;++i)
	{
		if(a[x]&(1<<i))lf[x][i]=rf[x][i]=x;
		else L=max(L,lf[l[x]][i]),R=min(R,rf[r[x]][i]);
		lf[x][i]=max(lf[x][i],max(lf[l[x]][i],lf[r[x]][i]));
		rf[x][i]=min(rf[x][i],min(rf[l[x]][i],rf[r[x]][i]));
	}
	ans+=1LL*(x-L)*(R-x);
}
int main()
{
	int n=read(),i;
	for(i=1;i<=n;++i)
	{
		a[i]=read();
		while(zn&&a[i]>a[z[zn]])l[i]=z[zn--];
		r[z[zn]]=i;z[++zn]=i;
	}
	memset(lf,200,sizeof(lf));memset(rf,40,sizeof(rf));
	dfs(z[1]);
	printf("%I64d",1LL*n*(n+1)/2-ans);
}