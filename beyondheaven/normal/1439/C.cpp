#include<bits/stdc++.h>
#define MaxN 400123
typedef long long LL;

#define int LL

int n,q;
int a[MaxN];

namespace SqrtTech
{
	const int Size=433;
	int bel[MaxN],val[MaxN/Size+123];
	
	inline void Init()
	{
		for(int i=1;i<=n;++i)
		bel[i]=(i-1)/Size+1;
	}
	
	inline void Modify(int x,int y)
	{
		for(int i=1;i<bel[x];++i)
		val[i]=std::max(val[i],y);
		for(int i=x;bel[i]==bel[x];--i)
		a[i]=std::max(a[i],y);
	}
	
	inline int Query(int x)
	{
		return std::max(a[x],val[bel[x]]);
	}
}

#define Mid ((L+R)>>1)
int st[MaxN<<2],ed[MaxN<<2],bg[MaxN],setv[MaxN<<2];
LL sum[MaxN<<2];

inline void Build(int k=1,int L=1,int R=n)
{
	st[k]=L;ed[k]=R;
	if(!bg[L])bg[L]=k;
	
	if(L==R)
	{
		sum[k]=a[L];
		return;
	}
	Build(k<<1,L,Mid);Build(k<<1|1,Mid+1,R);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}

inline void PushDown(int k,int L,int R)
{
	if(setv[k])
	{
		sum[k<<1]=setv[k]*(Mid-L+1);
		sum[k<<1|1]=setv[k]*(R-Mid);
		setv[k<<1]=setv[k<<1|1]=setv[k];
		setv[k]=0;
	}
}

inline void Modify(int l,int r,int v,int k=1,int L=1,int R=n)
{
	if(l<=L&&R<=r)
	{
		setv[k]=v;
		sum[k]=v*(R-L+1);
		return;
	}
	PushDown(k,L,R);
	if(l<=Mid)Modify(l,r,v,k<<1,L,Mid);
	if(Mid<r)Modify(l,r,v,k<<1|1,Mid+1,R);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}

inline LL Query(int l,int r,int k=1,int L=1,int R=n)
{
	if(l<=L&&R<=r)return sum[k];
	LL res=0;PushDown(k,L,R);
	if(l<=Mid)res+=Query(l,r,k<<1,L,Mid);
	if(Mid<r)res+=Query(l,r,k<<1|1,Mid+1,R);
	return res;
}

inline void Update(int k)
{
	if(k==1)return PushDown(k,st[k],ed[k]);
	Update(k>>1);
	if(st[k]!=ed[k])
	PushDown(k,st[k],ed[k]);
}

inline int BinarySearch(int l,int&v,int k)
{
	#ifdef Dubug
	printf("BinarySearch(%d,%d,%d)\n",k,st[k],ed[k]);
	#endif
	if(v>=sum[k])
	{
		v-=sum[k];
		return BinarySearch(l,v,bg[ed[k]+1]);
	}
	
	int L=st[k],R=ed[k];
	if(L==R)return L;
	PushDown(k,L,R);
	if(v>=sum[k<<1])
	{
		v-=sum[k<<1];
		return BinarySearch(l,v,k<<1|1);
	}
	else return BinarySearch(l,v,k<<1);
}
#undef Mid

inline int Work2(int x,int y)
{
	if(y<SqrtTech::Query(n))return 0;
	
	#ifdef Dubug
	printf("Work2(%d,%d)\n",x,y);
	#endif
	
	int L=x,R=n,Mid=0,res=0;
	while(L<=R)
	{
		Mid=((L+R)>>1);
		if(y<SqrtTech::Query(Mid))L=Mid+1;
		else
		{
			res=Mid;
			R=Mid-1;
		}
	}
	
	#ifdef Dubug
	printf("res=%d\n",res);
	#endif
	
	if(y>=Query(res,n))return n-res+1;
	
	Update(bg[res]);
	int ans=BinarySearch(res,y,bg[res])-res;
	#ifdef Dubug
	printf("ans=%d\n",ans);
	#endif
	return ans+Work2(res,y);
}

inline void Work1(int x,int y)
{
	if(SqrtTech::Query(x)>=y)return;
	
	int L=1,R=x,Mid=0,res=0;
	while(L<=R)
	{
		Mid=((L+R)>>1);
		if(SqrtTech::Query(Mid)>=y)L=Mid+1;
		else
		{
			res=Mid;
			R=Mid-1;
		}
	}
	
	Modify(res,x,y);
	SqrtTech::Modify(x,y);
}

//int main()
signed main()
{
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;++i)
	scanf("%lld",a+i);
	
	SqrtTech::Init();
	Build();
	
	for(int i=1,opt,x,y;i<=q;++i)
	{
		scanf("%lld%lld%lld",&opt,&x,&y);
		if(opt==1)Work1(x,y);
		else printf("%lld\n",Work2(x,y));
	}
	
	return 0;
}