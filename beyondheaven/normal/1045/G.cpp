#include<bits/stdc++.h>
const int MaxN = 100123;

#define Mid ((L+R)>>1)
std::map<int,int>mp;
int sum[MaxN<<5],ls[MaxN<<5],rs[MaxN<<5],cnt;
void Modify(int&o,int l,int L=0,int R=1e9)
{
	if(!o)o=++cnt;
	++sum[o];
	if(L==R)return;
	if(l<=Mid)Modify(ls[o],l,L,Mid);
	else Modify(rs[o],l,Mid+1,R);
}
int Query(int o,int l,int r,int L=0,int R=1e9)
{
	if(l<=L&&R<=r)return sum[o];
	int res=0;
	if(l<=Mid&&ls[o])res+=Query(ls[o],l,r,L,Mid);
	if(Mid<r&&rs[o])res+=Query(rs[o],l,r,Mid+1,R);
	return res;
}
#undef Mid

int n,k;
std::tuple<int,int,int>p[MaxN]; //(r,q,x)

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,x,r,q;i<=n;++i)
	{
		scanf("%d%d%d",&x,&r,&q);
		p[i]=std::tuple<int,int,int>{r,q,x};
	}
	
	std::sort(p+1,p+n+1);
	std::reverse(p+1,p+n+1);
	
	long long ans=0;
	for(int i=1;i<=n;++i)
	{
		int r=std::get<0>(p[i]),
			q=std::get<1>(p[i]),
			x=std::get<2>(p[i]);
			
		for(int j=q-k;j<=q+k;++j)if(mp.count(j))
		ans+=Query(mp[j],std::max(x-r,0),std::min(x+r,(int)(1e9)));
		
		if(!mp.count(q))mp.insert({q,0});
		Modify(mp[q],x);
	}
	
	printf("%lld\n",ans);
	return 0;
}