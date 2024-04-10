#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<queue>
#define int long long
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,K,P,h[100001],a[100001],ans,l,r;
struct data
{
	int day,id,high;
	data(int _day=0,int _id=0,int _high=0){day=_day,id=_id,high=_high;}
	bool operator <(const data &x)const
	{
		return x.day<day;
	}
};
priority_queue<data> Q;
int check(int lim)
{
	while(!Q.empty())
		Q.pop();
	for(int i=1;i<=n;++i)
		if(lim-a[i]*m<h[i])
			Q.push(data(lim/a[i]+1,i,lim));
	for(int i=1;i<=m && !Q.empty();++i)
	{
		if((Q.top()).day<=i)
			return 0;
		for(int j=1;j<=K && !Q.empty();++j)
		{
			data u=Q.top();
			Q.pop();
			u.high+=P;
			if(u.high-a[u.id]*m<h[u.id])
			{
				u.day=u.high/a[u.id]+1;
				Q.push(u);
			}
		}
	}
	return Q.empty();
}
signed main()
{
	n=read(),m=read(),K=read(),P=read();
	for(int i=1;i<=n;++i)
	{
		h[i]=read(),a[i]=read();
		r=max(r,h[i]+a[i]*m);
	}
	while(l<=r)
	{
		int mid=(l+r)/2;
		//cout<<"WRP AK IOI "<<mid<<" "<<check(mid)<<endl;
		if(check(mid))
			ans=mid,r=mid-1;
		else
			l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}