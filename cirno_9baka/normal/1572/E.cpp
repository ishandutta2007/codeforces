#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,k,f[N][N];
long long lim,g[N][N];
struct str{
	long long x,y;
}a[N];
str operator -(str a,str b)
{
	return {a.x-b.x,a.y-b.y};
}
long long operator *(str a,str b)
{
	return a.x*b.y-a.y*b.x;
}
long long area(str a,str b,str c)
{
	return abs((c-a)*(b-a));
}
void dfs(int l,int r)
{
	if(r==l+1)
	{
		f[l][r]=0;
		return;
	}
	if(f[l][r]!=-1)
		return;
	for(int i=l+1;i<r;++i)
	{
		dfs(l,i);
		dfs(i,r);
		if(f[l][r]<f[l][i]+f[i][r])
		{
			f[l][r]=f[l][i]+f[i][r];
			g[l][r]=area(a[l],a[i],a[r])+g[l][i]+g[i][r];
		}
		else
			if(f[l][r]==f[l][i]+f[i][r])
				g[l][r]=max(g[l][r],area(a[l],a[i],a[r])+g[l][i]+g[i][r]);
	}
	if(g[l][r]>=lim)
	{
		g[l][r]=0;
		++f[l][r];
	}
}
bool check(long long m)
{
	lim=m;
	memset(f,-1,sizeof(f));
	memset(g,0,sizeof(g));
	dfs(1,n);
	return f[1][n]>=k+1;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%lld %lld",&a[i].x,&a[i].y);
	long long l=1,r=80000000000000001ll;
	while(l<r)
	{
		long long mid=l+r>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid;
	}
	cout<<l-1;
}