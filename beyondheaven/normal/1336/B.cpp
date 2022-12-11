#include<bits/stdc++.h>
typedef long long LL;
typedef std::vector<int> IVec;
const LL Inf=0x3f3f3f3f3f3f3f3fLL;
inline LL F(int x,int y,int z)
{
	#ifdef Dubug
	printf("F(%d,%d,%d);\n",x,y,z);
	#endif
	return 1LL*(x-y)*(x-y)+1LL*(y-z)*(y-z)+1LL*(z-x)*(z-x);
}
inline LL Calc(IVec&a,IVec&b,IVec&c)
{
	LL ans=Inf;
	for(auto y:b)
	{
		auto p1=lower_bound(a.begin(),a.end(),y);
		auto p2=upper_bound(c.begin(),c.end(),y);
		if(p1!=a.end()&&p2!=c.begin())
		ans=std::min(ans,F(*p1,y,*(p2-1)));
	}
	#ifdef Dubug
	//printf("ans=%lld\n",ans);
	#endif
	return ans;
}
IVec nr,ng,nb;
int r,g,b;
inline void Init()
{
	scanf("%d%d%d",&r,&g,&b);
	nr.clear();ng.clear();nb.clear();
	for(int i=1,x;i<=r;++i)
	{
		scanf("%d",&x);
		nr.push_back(x);
	}
	for(int i=1,x;i<=g;++i)
	{
		scanf("%d",&x);
		ng.push_back(x);
	}
	for(int i=1,x;i<=b;++i)
	{
		scanf("%d",&x);
		nb.push_back(x);
	}
	std::sort(nr.begin(),nr.end());
	std::sort(nb.begin(),nb.end());
	std::sort(ng.begin(),ng.end());
}
inline void Solve()
{
	LL ans=Inf;
	ans=std::min(ans,Calc(nr,ng,nb));
	ans=std::min(ans,Calc(nr,nb,ng));
	ans=std::min(ans,Calc(ng,nr,nb));
	ans=std::min(ans,Calc(ng,nb,nr));
	ans=std::min(ans,Calc(nb,nr,ng));
	ans=std::min(ans,Calc(nb,ng,nr));
	printf("%lld\n",ans);
}
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		Init();
		Solve();
	}
	return 0;
}