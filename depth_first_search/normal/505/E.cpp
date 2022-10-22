#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define LL long long
#define mp make_pair
#define Pr pair<LL,LL>
#define fi first
#define se second
using namespace std;
int n,m,k,p,h[N+5],a[N+5];vector<int> V[N+5];vector<int>::iterator it;
LL s[N+5];I bool Check(Con LL& x)
{
	#define Push(id,x) (id)<m&&(V[id].push_back(x),0)
	RI i;for(i=0;i^m;++i) V[i].clear();for(i=1;i<=n;++i) Push((s[i]=x)/a[i],i);
	RI t=0;LL d;for(i=0;i^m;++i) for(it=V[i].begin();it!=V[i].end();++it)
	{
		d=(1LL*a[*it]*(i+1)-s[*it]+p-1)/p;
		if(s[*it]+=d*p,(t+=d)>i*k) return false;Push(s[*it]/a[*it],*it);
	}
	for(i=1;i<=n;++i) if(s[i]<1LL*a[i]*m+h[i])
		if(d=(1LL*a[i]*m+h[i]-s[i]+p-1)/p,(t+=d)>m*k) return false;return true;
}
int main()
{
	RI i;for(scanf("%d%d%d%d",&n,&m,&k,&p),i=1;i<=n;++i) scanf("%d%d",h+i,a+i);
	LL l=0,r=1e13,mid;W(l^r) Check(mid=l+r>>1)?r=mid:l=mid+1;return printf("%lld\n",r),0;
}