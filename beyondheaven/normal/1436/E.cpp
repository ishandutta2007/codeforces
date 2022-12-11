#include<bits/stdc++.h>
#define MaxN 100123
int n;
int a[MaxN];

bool vis[MaxN];
std::vector<std::pair<int,int> >q[MaxN];

#define Mid ((L+R)>>1)
int minv[MaxN<<2];
inline void Modify(int l,int v,int k=1,int L=1,int R=n)
{
	if(L==R)
	{
		minv[k]=v;
		return;
	}
	if(l<=Mid)Modify(l,v,k<<1,L,Mid);
	else Modify(l,v,k<<1|1,Mid+1,R);
	minv[k]=std::min(minv[k<<1],minv[k<<1|1]);
}
inline int Query(int l,int r,int k=1,int L=1,int R=n)
{
	if(l<=L&&R<=r)return minv[k];
	int res=0x3f3f3f3f;
	if(l<=Mid)res=std::min(res,Query(l,r,k<<1,L,Mid));
	if(Mid<r)res=std::min(res,Query(l,r,k<<1|1,Mid+1,R));
	return res;
}
#undef Mid

std::vector<int>occ[MaxN];

int main()
{
	scanf("%d",&n);
	bool all=true;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		all&=(a[i]==1);
		occ[a[i]].push_back(i);
	}
	if(all)
	{
		puts("1");
		return 0;
	}
	for(int i=2;i<=n+1;++i)
	{
		int last=0;
		for(int x:occ[i])
		{
			if(last+1<=x-1)
			q[x-1].push_back(std::make_pair(last+1,i-1));
			last=x;
		}
		if(last+1<=n)
		q[n].push_back(std::make_pair(last+1,i-1));
	}
	for(int i=1;i<=n;++i)
	{
		Modify(a[i],i);
		for(auto&p:q[i])
		{
			if(Query(1,p.second)>=p.first)
			vis[p.second+1]=1;
		}
	}
	
	for(int i=2;i<=n+2;++i)
	if(!vis[i])
	{
		printf("%d\n",i);
		return 0;
	}
	return 0;
}