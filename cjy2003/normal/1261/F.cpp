#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int mod=998244353;
int na,nb;
struct st
{
	int n;
	long long S[61][1010];
	int cnt,p[12010];
	long long w[12010];
	void add(int k,long long l,long long r,long long ll,long long rr,long long cur)
	{
		if(l>rr||r<ll)return ;
	//	printf("%d\n",k);
		S[k][++S[k][0]]=cur;
		if(l>=ll&&r<=rr)
		{
			++cnt;
	//		printf("%d %d %lld\n",cnt,k,cur);
			p[cnt]=k,w[cnt]=cur;
			return ;
		}
		add(k-1,l,l+r>>1,ll,rr,cur<<1);
		add(k-1,(l+r>>1)+1,r,ll,rr,cur<<1|1);
	}
	void init()
	{
		scanf("%d",&n);
		long long x,y;
		for(int i=1;i<=n;++i)
		{
			scanf("%lld %lld",&x,&y);
			add(60,0,(1ll<<60)-1,x,y,0);
		}
	//	for(int i=1;i<=cnt;++i)printf("%d %lld\n",p[i],w[i]);
	//	printf("\n");
	}
}a,b;
struct line
{
	long long l,r;
	friend bool operator < (line a,line b){return a.l<b.l;}
}l[10000000];
int cnt;
#define ins(a,p) l[++cnt]=line{(a)<<p,((a)+1<<p)-1}
int ans;
inline int calc(long long a,long long b)
{
//	printf("c %lld %lld\n",a,b);
	a%=mod,b%=mod;
	return 1ll*(a+b)*(b+mod-a+1)%mod*499122177%mod;
}
int main()
{
	a.init();b.init();
	for(int i=1;i<=a.cnt;++i)
		for(int j=1;j<=b.S[a.p[i]][0];++j)/*printf("%lld %lld %lld %lld\n",a.w[i]<<a.p[i],(a.w[i]+1<<a.p[i])-1,b.S[a.p[i]][j]<<a.p[i],(b.S[a.p[i]][j]+1<<a.p[i])-1),*/ins(a.w[i]^b.S[a.p[i]][j],a.p[i]);
	for(int i=1;i<=b.cnt;++i)
		for(int j=1;j<=a.S[b.p[i]][0];++j)/*printf("%lld %lld %lld %lld\n",b.w[i]<<b.p[i],(b.w[i]+1<<b.p[i])-1,a.S[b.p[i]][j]<<b.p[i],(a.S[b.p[i]][j]+1<<b.p[i])-1),*/ins(b.w[i]^a.S[b.p[i]][j],b.p[i]);
	sort(l+1,l+1+cnt);
//	for(int i=1;i<=cnt;++i)printf("%lld %lld\n",l[i].l,l[i].r);
	long long last=0,pl=0;
	for(int i=1;i<=cnt;++i)
	{
		if(l[i].l<=last)last=max(last,l[i].r);
		else
		{
			(ans+=calc(pl,last))>=mod?ans-=mod:0;
			pl=l[i].l,last=l[i].r;
		}
	}
	(ans+=calc(pl,last))>=mod?ans-=mod:0;
	printf("%d",ans);
	return 0;
}