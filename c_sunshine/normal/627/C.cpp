#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int maxn=200005;
LL ans;
int m,d,n;
int nex[maxn];
struct sta
{
	int x,p;
	bool operator<(const sta &o)const
	{return x<o.x;}
}s[200005];

int st[400005][19],lg2[maxn];

int gmin(int l,int r)
{
	r++;
	int k=lg2[r-l];
	return min(st[l][k],st[r-(1<<k)][k]);
}

int R;

void addoil(int k,int p)
{
	if(k>R)ans+=(LL)(k-R)*p,R=k;
}

void drive(int i,int j)
{
	addoil(s[j].x-s[i].x,s[i].p);
	R-=s[j].x-s[i].x;
}

int main()
{
	scanf("%d%d%d",&d,&m,&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&s[i].x,&s[i].p);
	sort(s+1,s+n+1);
	s[n+1].x=d;
	lg2[0]=-1;
	for(int i=1;i<maxn;i++)lg2[i]=lg2[i>>1]+1;
	for(int i=0;i<=n+1;i++)st[i][0]=s[i].p;
	for(int j=1;j<=17;j++)
		for(int i=0;i<=n+1;i++)
			st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
	for(int i=0,j=0;i<=n;i++)
	{
		for(;j<=n+1&&s[j].x<=s[i].x+m;j++);
		if(j-i<=1){cout<<-1;return 0;}
		int low=i,high=j,mid;
		while(low+1<high)
		{
			mid=low+high>>1;
			if(gmin(i+1,mid)<s[i].p)high=mid;
			else low=mid;
		}
		if(high==j)nex[i]=-1;
		else nex[i]=high;
	}
	R=m;
	for(int i=0;i<n+1;i=nex[i])
	{
		if(nex[i]==-1)
			addoil(min(m,d-s[i].x),s[i].p),nex[i]=i+1;
		drive(i,nex[i]);
	}
	cout<<ans<<endl;
	return 0;
}