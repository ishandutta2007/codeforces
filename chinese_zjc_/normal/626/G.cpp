#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

const long double eps=1e-12;

int n,t,q,p[200050],l[200050],c[200050],tk[200050],rk[200050];

long double ans=0;

inline long double calc(int i,int x)
{
	return 1.0*p[i]*l[i]/(1.0*(l[i]+c[i])*(l[i]+c[i]+x));
}

inline int comp(long double x)
{
	if (x<-eps)
		return -1;
	else
		return x>eps;
}

struct node
{
	long double ev;
	int x;
	bool operator < (const node & rhs) const
	{
		if (comp(ev-rhs.ev))
			return ev<rhs.ev;
		else
			return x<rhs.x;
	}
};

multiset <node> a,b;

inline void Add(int u)
{
	if (c[u]<l[u])
		a.erase({calc(u,1),u});
	if (c[u])
		b.erase({calc(u,-1),u});
	ans+=calc(u,1);
	c[u]++;
	t--;
	if (c[u]<l[u])
		a.insert({calc(u,1),u});
	if (c[u])
		b.insert({calc(u,-1),u});
}

inline void Del(int u)
{
	if (c[u]<l[u])
		a.erase({calc(u,1),u});
	if (c[u])
		b.erase({calc(u,-1),u});
	ans-=calc(u,-1);
	c[u]--;
	t++;
	if (c[u]<l[u])
		a.insert({calc(u,1),u});
	if (c[u])
		b.insert({calc(u,-1),u});
}

int main()
{
	n=read(),t=read(),q=read();
	for (int i=1;i<=n;i++)
		p[i]=read();
	for (int i=1;i<=n;i++)
	{
		l[i]=read();
		if (c[i]<l[i])
			a.insert({calc(i,1),i});
		if (c[i])
			b.insert({calc(i,-1),i});
	}
	while (t && a.size())
		Add(a.rbegin()->x);
	for (int i=1;i<=q;i++)
	{
		tk[i]=read();
		rk[i]=read();
		
		if (c[rk[i]]==l[rk[i]] && tk[i]==2)
			Del(rk[i]);	
		if (c[rk[i]]<l[rk[i]])
			a.erase({calc(rk[i],1),rk[i]});
		if (c[rk[i]])
			b.erase({calc(rk[i],-1),rk[i]});
		ans-=1.0*p[rk[i]]*c[rk[i]]/(l[rk[i]]+c[rk[i]]);
		l[rk[i]]+=(tk[i]==1)?1:-1;
		if (c[rk[i]]<l[rk[i]])
			a.insert({calc(rk[i],1),rk[i]});
		if (c[rk[i]])
			b.insert({calc(rk[i],-1),rk[i]});
		ans+=1.0*p[rk[i]]*c[rk[i]]/(l[rk[i]]+c[rk[i]]);
		if (t && a.size())
			Add(a.rbegin()->x);
		if (a.size() && b.size() && comp(a.rbegin()->ev-b.begin()->ev)>0)
		{
			int X=b.begin()->x,Y=a.rbegin()->x;
			Del(X);
			Add(Y);
		}
		cout << fixed << setprecision(12) << ans << endl;
	}
	return 0;
}