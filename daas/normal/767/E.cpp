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
int read()
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
int n,m,c[100001],w[100001],pd[100001],ans;
struct data
{
	int value,id;
	data(int _value=0,int _id=0){value=_value,id=_id;}
	bool operator <(const data &x)const
	{
		return x.value<value;
	}
};
priority_queue<data> Q;
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;++i)
		c[i]=read();
	for(int i=1;i<=n;++i)
		w[i]=read();
	for(int i=1;i<=n;++i)
	{
		if(c[i]%100==0)
			continue;
		int Need=c[i]%100,cost=(100-Need)*w[i];
		Q.push(data(cost,i));
		if(m<Need)
		{
			data u=Q.top();
			Q.pop();
			pd[u.id]=1;
			ans+=u.value;
			m+=100;
		}
		m-=Need;
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=n;++i)
		if(c[i]%100==0)
			printf("%I64d 0\n",c[i]/100);
		else
		{
			int Need=c[i]%100;
			if(pd[i])
				printf("%I64d 0\n",c[i]/100+1);
			else
				printf("%I64d %I64d\n",c[i]/100,Need);
		}
	return 0;
}