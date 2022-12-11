#include<bits/stdc++.h>
const int MaxN = 500123;

struct Q
{
	int l,id;
	Q(int _l=0,int _id=0):
		l(_l),id(_id){}
};
std::vector<Q>q[MaxN];

int n,m,a[MaxN],ans[MaxN];
int b[22],c[22];

void Insert(int x,int p)
{
	for(int i=21;~i;--i)
	if((x>>i)&1)
	{
		if(!b[i])
		return b[i]=x,c[i]=p,void();
		if(c[i]<p)std::swap(c[i],p),std::swap(b[i],x);
		x^=b[i];
	}
}

int Query(int l)
{
	int res=0;
	for(int i=21;~i;--i)
	if(c[i]>=l && (res^b[i])>res)res^=b[i];
	return res;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=1,l,r;i<=m;++i)
	{
		scanf("%d%d",&l,&r);
		q[r].push_back(Q(l,i));
	}
	
	for(int i=1;i<=n;++i)
	{
		Insert(a[i],i);
		for(Q&o:q[i])
		ans[o.id]=Query(o.l);
	}
	
	for(int i=1;i<=m;++i)
	printf("%d\n",ans[i]);
	return 0;
}