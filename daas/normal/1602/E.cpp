#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
#define lowbit(k) (k&-k)
using namespace std;
const int MAXN=1e6+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,m,a[MAXN],b[MAXN],tree[MAXN*2],num[MAXN*2],cnt,P[MAXN];
ll ans;
void xg(int zone,int val)
{
	while(zone<=cnt)
	{
		tree[zone]+=val;
		zone+=lowbit(zone);
	}
}
int cx(int zone)
{
	int bck=0;
	while(zone)
	{
		bck+=tree[zone];
		zone-=lowbit(zone);
	}
	return bck;
}
void solve(int l,int r,int L,int R)
{
	if(L>R) return;
	int mid=(L+R)>>1,val=0,minn,p=l;
	for(int i=l+1;i<=r;++i) val+=(a[i]<b[mid]);
	minn=val;
	for(int i=l+1;i<=r;++i)
	{
		if(a[i]<b[mid]) --val;
		if(a[i]>b[mid]) ++val;
		if(val<minn) minn=val,p=i;
	}
	P[mid]=p;
	solve(l,p,L,mid-1);
	solve(p,r,mid+1,R);
}
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		cnt=0;
		for(int i=1;i<=n;++i) num[++cnt]=a[i]=read();
		for(int i=1;i<=m;++i) num[++cnt]=b[i]=read();
		sort(b+1,b+m+1);
		sort(num+1,num+cnt+1);
		cnt=unique(num+1,num+cnt+1)-num-1;
		for(int i=1;i<=cnt;++i) tree[i]=0;
		solve(0,n,1,m);
		ans=0;
		int bj=0,tot=0;
		for(int i=1;i<=n;++i)
		{
			while(bj+1<=m && P[bj+1]==i-1)
			{
				++bj;
				++tot;
				int id=lower_bound(num+1,num+cnt+1,b[bj])-num;
				xg(id,1);
				ans+=tot-cx(id);
			}
			++tot;
			int id=lower_bound(num+1,num+cnt+1,a[i])-num;
			xg(id,1);
			ans+=tot-cx(id);
		}
		while(bj+1<=m)
		{
			++bj;
			++tot;
			int id=lower_bound(num+1,num+cnt+1,b[bj])-num;
			xg(id,1);
			ans+=tot-cx(id);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
//ore no turn,draw!