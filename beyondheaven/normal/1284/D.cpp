#include<cstdio>
#include<algorithm>
#define MaxN 100123
template<typename T>
inline void read(T&x)
{
	x=0;int ch=getchar();
	while(ch<48||ch>57)ch=getchar();
	while(ch>47&&ch<58)x=10*x+ch-48,ch=getchar();
}
using std::min;
using std::max;
int n,s;
bool ans;
int sa[MaxN],ea[MaxN],sb[MaxN],eb[MaxN];
int b[MaxN<<1];
int rks[MaxN],rke[MaxN];
int minv[MaxN<<3],maxv[MaxN<<3];
int tmin[MaxN<<3],tmax[MaxN<<3];
inline void Init()
{
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(sa[i]);read(ea[i]);
		read(sb[i]);read(eb[i]);
	}
}
inline void Disc()
{
	int p=0;
	for(int i=1;i<=n;++i)
	{
		b[++p]=sa[i];b[++p]=ea[i];
	}
	std::sort(b+1,b+p+1);
	s=std::unique(b+1,b+p+1)-b-1;
	for(int i=1;i<=n;++i)
	{
		rks[i]=std::lower_bound(b+1,b+s+1,sa[i])-b;
		rke[i]=std::lower_bound(b+1,b+s+1,ea[i])-b;
	}
}
#define Mid ((L+R)>>1)
inline void Build(int k=1,int L=1,int R=s)
{
	tmin[k]=minv[k]=0x3f3f3f3f;
	tmax[k]=maxv[k]=0;
	if(L==R)return;
	Build(k<<1,L,Mid);Build(k<<1|1,Mid+1,R);
}
inline void PushDown(int k)
{
	minv[k<<1]=min(minv[k<<1],tmin[k]);
	tmin[k<<1]=min(tmin[k<<1],tmin[k]);
	minv[k<<1|1]=min(minv[k<<1|1],tmin[k]);
	tmin[k<<1|1]=min(tmin[k<<1|1],tmin[k]);
	maxv[k<<1]=max(maxv[k<<1],tmax[k]);
	tmax[k<<1]=max(tmax[k<<1],tmax[k]);
	maxv[k<<1|1]=max(maxv[k<<1|1],tmax[k]);
	tmax[k<<1|1]=max(tmax[k<<1|1],tmax[k]); 
}
inline void ModifyMin(int l,int r,int v,int k=1,int L=1,int R=s)
{
	if(l<=L&&R<=r)
	{
		minv[k]=min(minv[k],v);
		tmin[k]=min(tmin[k],v);
		return;
	}
	PushDown(k);
	if(l<=Mid)ModifyMin(l,r,v,k<<1,L,Mid);
	if(Mid<r)ModifyMin(l,r,v,k<<1|1,Mid+1,R);
	minv[k]=min(minv[k<<1],minv[k<<1|1]);
}
inline void ModifyMax(int l,int r,int v,int k=1,int L=1,int R=s)
{
	if(l<=L&&R<=r)
	{
		maxv[k]=max(maxv[k],v);
		tmax[k]=max(tmax[k],v);
		return;
	}
	PushDown(k);
	if(l<=Mid)ModifyMax(l,r,v,k<<1,L,Mid);
	if(Mid<r)ModifyMax(l,r,v,k<<1|1,Mid+1,R);
	maxv[k]=max(maxv[k<<1],maxv[k<<1|1]);
}
inline int QueryMin(int l,int r,int k=1,int L=1,int R=s)
{
	if(l<=L&&R<=r)return minv[k];
	int res=0x3f3f3f3f;PushDown(k);
	if(l<=Mid)res=min(res,QueryMin(l,r,k<<1,L,Mid));
	if(Mid<r)res=min(res,QueryMin(l,r,k<<1|1,Mid+1,R));
	return res;
}
inline int QueryMax(int l,int r,int k=1,int L=1,int R=s)
{
	if(l<=L&&R<=r)return maxv[k];
	int res=0;PushDown(k);
	if(l<=Mid)res=max(res,QueryMax(l,r,k<<1,L,Mid));
	if(Mid<r)res=max(res,QueryMax(l,r,k<<1|1,Mid+1,R));
	return res;
}
inline void Solve()
{
	for(int i=1;i<=n;++i)
	{
		if(QueryMin(rks[i],rke[i])<sb[i]
		||QueryMax(rks[i],rke[i])>eb[i])
		{ans=1;return;}
		ModifyMin(rks[i],rke[i],eb[i]);
		ModifyMax(rks[i],rke[i],sb[i]);
	}
}
inline void Rev()
{
	for(int i=1;i<=n;++i)
	{
		std::swap(sa[i],sb[i]);
		std::swap(ea[i],eb[i]);
	}
}
int main()
{
	Init();
	Disc();
	Build();
	Solve();
	Rev();
	Disc();
	Build();
	Solve();
	if(ans)puts("NO");
	else puts("YES");
	return 0;
}