#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,fa[100005],dp[100005],sz[100005],cnt[100005],x,y,ans;
struct ii
{
	int x,cst;
};
vector<ii> v;
int fnd(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}
bool check(int x)
{
	while (x)
	{
		if (x%10!=4&&x%10!=7) return 0;
		x/=10;
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,n) fa[i]=i;
	fz1(i,m)
	{
		scanf("%d%d",&x,&y);
		fa[fnd(x)]=fnd(y);
	}
	fz1(i,n) sz[fnd(i)]++;
	fz1(i,n) cnt[sz[i]]++;
	fz1(i,n)
	{
		for (j=1;j<=cnt[i];j*=2)
		{
			v.push_back((ii){j*i,j});
			cnt[i]-=j;
		}
		if (cnt[i])
		{
			v.push_back((ii){cnt[i]*i,cnt[i]});
		}
	}
	memset(dp,22,sizeof(dp));
	dp[0]=0;
	/*for (i=0;i<v.size();i++)
	{
		cerr<<v[i].x<<' '<<v[i].cst<<endl;
	}*/
	for (i=0;i<v.size();i++)
	{
		for (j=n;j>=v[i].x;j--)
		{
			dp[j]=min(dp[j],dp[j-v[i].x]+v[i].cst);
		}
	}
	ans=0x16161616;
	fz1(i,n)
	{
		if (check(i)) ans=min(ans,dp[i]);
	}
	if (ans==0x16161616) cout<<-1<<endl; else cout<<ans-1<<endl;
	return 0;
}