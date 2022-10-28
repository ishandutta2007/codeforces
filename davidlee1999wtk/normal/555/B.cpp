#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 200005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<LL,int> pii;
LL a[N],b[N];
map<LL,int> mp;
struct Qu
{
	LL fi,se;
	int num;
	bool operator<(const Qu &t) const
	{
		return fi<t.fi;
	}
}q[N];
int sum[N];
vector<int> G[N];
priority_queue<pii,vector<pii>,greater<pii> > qu;
int ans[N];
int main()
{
	ios::sync_with_stdio(false);
	int n,m,z,i,j=1,k,l;
	LL t;
	pii x;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>q[i].fi>>q[i].se;
		q[i].num=i;
		//debug(q[i].fi);
	}
	n--;
	for(i=1;i<=n;i++)
	{
		t=q[i].fi;
		q[i].fi=q[i+1].fi-q[i].se,q[i].se=q[i+1].se-t;
	}
	sort(q+1,q+1+n);
	for(i=1;i<=m;i++)
		cin>>a[i],b[i]=a[i];
	sort(b+1,b+1+m);
	z=unique(b+1,b+1+m)-(b+1);
	for(i=1;i<=z;i++)
		mp[b[i]]=i;
	for(i=1;i<=m;i++)
		a[i]=mp[a[i]],sum[a[i]]++,G[a[i]].push_back(i);
	for(i=1;i<=z;i++)
	{
		while(q[j].fi<=b[i]&&j<=n)
		{
			qu.push(MP(q[j].se,q[j].num));
			j++;
		}
		k=sum[i];
		l=0;
		while(!qu.empty()&&k--)
		{
			x=qu.top();
			qu.pop();
			if(x.fi<b[i])
			{
				printf("No\n");
				return 0;
			}
			ans[x.se]=G[i][l];
			l++;
		}
	}
	if(!qu.empty()||j<=n)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);