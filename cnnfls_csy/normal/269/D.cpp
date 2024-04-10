#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<set>
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
int n,m,i,j,l[100005],r[100005],h[100005],dp[100005];
vector<pair<int,int> > bi[100005];
struct ii
{
	int x,op,h,id;
};
vector<ii> v;
bool cmp(ii x,ii y)
{
	if (x.x<y.x) return 1;
	if (x.x>y.x) return 0;
	if (x.op<y.op) return 1;
	if (x.op>y.op) return 0;
	return x.h<y.h;
}
int calc(int x,int y)
{
	return min(r[x],r[y])-max(l[x],l[y]);
}
int dfs(int x)
{
	if (x==n+1) return 2e9;
	if (dp[x]!=-1) return dp[x];
	dp[x]=0;
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		dp[x]=max(dp[x],min(dfs(bi[x][i].first),bi[x][i].second));
	}
	return dp[x];
}
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,n)
	{
		scanf("%d%d%d",&h[i],&l[i],&r[i]);
		v.push_back((ii){l[i],1,h[i],i});
		v.push_back((ii){r[i],-1,h[i],i});
	}
	sort(v.begin(),v.end(),cmp);
	set<pair<int,int> > s;
	l[0]=l[n+1]=-1e9;
	r[0]=r[n+1]=1e9;
	s.insert(make_pair(0,0));
	s.insert(make_pair(m,n+1));
	for (i=0;i<v.size();i++)
	{
		if (v[i].op==1)
		{
			s.insert(make_pair(v[i].h,v[i].id));
			set<pair<int,int> >::iterator nxt=s.lower_bound(make_pair(v[i].h,v[i].id)),pre;
			pre=nxt;
			pre--;
			nxt++;
			int pre2=pre->second,nxt2=nxt->second;
			if (!bi[pre2].empty()&&bi[pre2].back().first==nxt2)
			{
				bi[pre2].pop_back();
			}
			bi[pre2].push_back(make_pair(v[i].id,calc(v[i].id,pre2)));
			bi[v[i].id].push_back(make_pair(nxt2,calc(v[i].id,nxt2)));
		}
		else
		{
			s.erase(make_pair(v[i].h,v[i].id));
		}
	}
//	cerr<<s.size()<<endl;
/*	for (i=0;i<=n+1;i++)
	{
		cerr<<i<<':'<<endl;
		ff(bi[i],it)cerr<<it->first<<' '<<it->second<<endl;
	}*/
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0)<<endl;
	return 0;
}