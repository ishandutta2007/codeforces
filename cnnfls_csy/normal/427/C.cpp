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
long long n,m,i,j,col[100005],mi[100005],f[100005],ans,ans2=1,vis[100005],cst[100005],x,y,cnt,mod=1e9+7;
vector<long long> bi[100005],nbi[100005],seq;
void dfs(int x)
{
	if (vis[x]) return;
	vis[x]=1;
	ff(nbi[x],it) dfs(*it);
	seq.push_back(x);
}
void dfs2(int x,int cnt)
{
	if (col[x]) return;
	col[x]=cnt;
	ff(bi[x],it) dfs2(*it,cnt);
}
int main()
{
	scanf("%I64d",&n);
	fz1(i,n) scanf("%I64d",&cst[i]);
	scanf("%I64d",&m);
	fz1(i,m)
	{
		scanf("%I64d%I64d",&x,&y);
		bi[x].push_back(y);
		nbi[y].push_back(x);
	}
	fz1(i,n)
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}
	reverse(seq.begin(),seq.end());
	fz0k(i,n)
	{
		if (!col[seq[i]])
		{
			cnt++;
			mi[cnt]=1ll<<55;
			dfs2(seq[i],cnt);
		}
	}
	fz1(i,n)
	{
		if (cst[i]<mi[col[i]])
		{
			mi[col[i]]=cst[i];
			f[col[i]]=0;
		}
		if (cst[i]==mi[col[i]])
		{
			f[col[i]]++;
		}
	}
	fz1(i,cnt)
	{
		ans+=mi[i];
		(ans2*=f[i])%=mod;
	}
	printf("%I64d %I64d\n",ans,ans2);
	return 0;
}