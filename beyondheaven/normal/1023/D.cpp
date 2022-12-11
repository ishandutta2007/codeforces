#include<bits/stdc++.h>
#define MaxN 200123
int n,q;
int a[MaxN],lm[MaxN],rm[MaxN];
int minv[MaxN<<2],maxv[MaxN<<2],tag[MaxN<<2];
inline void Init()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
	scanf("%d",a+i);
	for(int i=1;i<=n;++i)
	{
		if(!a[i])continue;
		if(!lm[a[i]])lm[a[i]]=i;
		if(!rm[a[i]])rm[a[i]]=i;
		lm[a[i]]=std::min(lm[a[i]],i);
		rm[a[i]]=std::max(rm[a[i]],i);
	}
}
#define Mid ((L+R)>>1) 
inline void Build(int k=1,int L=1,int R=n)
{
	if(L==R)
	{
		minv[k]=(a[L]?a[L]:0x3f3f3f3f);return;
	}
	Build(k<<1,L,Mid);Build(k<<1|1,Mid+1,R);
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
inline void Build2(int k=1,int L=1,int R=n)
{
	if(L==R)
	{
		maxv[k]=a[L];return;
	}
	Build2(k<<1,L,Mid);Build2(k<<1|1,Mid+1,R);
	maxv[k]=std::max(maxv[k<<1],maxv[k<<1|1]);
}
inline void PushDown(int k)
{
	maxv[k<<1]=std::max(maxv[k<<1],tag[k]);
	maxv[k<<1|1]=std::max(maxv[k<<1|1],tag[k]);
	tag[k<<1]=std::max(tag[k<<1],tag[k]);
	tag[k<<1|1]=std::max(tag[k<<1|1],tag[k]);
}
inline void Modify(int l,int r,int v,int k=1,int L=1,int R=n)
{
	if(l<=L&&R<=r)
	{
		maxv[k]=std::max(maxv[k],v);
		tag[k]=std::max(tag[k],v);
		return;
	}
	PushDown(k);
	if(l<=Mid)Modify(l,r,v,k<<1,L,Mid);
	if(Mid<r)Modify(l,r,v,k<<1|1,Mid+1,R);
	maxv[k]=std::max(maxv[k<<1],maxv[k<<1|1]);
}
inline void Print(int k=1,int L=1,int R=n)
{
	if(L==R)
	{
		printf("%d ",maxv[k]?maxv[k]:1);
		return;
	}
	PushDown(k);
	Print(k<<1,L,Mid);Print(k<<1|1,Mid+1,R);
}
#undef Mid
inline void Solve()
{
	if(std::all_of(a+1,a+n+1,[](int x){return x!=q&&x!=0;}))
	{
		puts("NO");
		return;
	}
	Build();
	for(int i=1;i<=q;++i)
	{
		if(!lm[i])continue;
		if(Query(lm[i],rm[i])<i)
		{
			puts("NO");
			return;
		}
	}
	puts("YES");
	if(std::all_of(a+1,a+n+1,[](int x){return x!=q;}))
	{
		for(int i=1;i<=n;++i)
		if(!a[i]){a[i]=q;break;}
	}
	Build2();
	for(int i=1;i<=q;++i)
	{
		if(!lm[i])continue;
		Modify(lm[i],rm[i],i);
	}
	Print();
}
int main()
{
	Init();
	Solve();
	return 0;
}