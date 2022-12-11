#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const long long mod=1000000007;
inline long long kpow(long long a,long long b)
{
	a%=mod,b%=(mod-1);
	long long s=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)s=s*a%mod;
	return s;
}
void no()
{
	printf("-1");
	exit(0);
}
long long n,a[110],b[110],mib=0x3f3f3f3f;
bool bj[100010];
long long su[100010],sunum;
void init()
{
	bj[1]=1;
	for(long long i=2;i<=100000;++i)
	{
		if(!bj[i])su[++sunum]=i;
		for(long long j=1;j<=sunum&&su[j]*i<=100000;++j)
		{
			bj[su[j]*i]=1;
			if(i%su[j]==0)break;
		}
	}
}
map<long long,long long>mp;
bool check(long long w)
{
	for(long long s=w,i=1;s<=1000000000;s*=w,++i)mp[s]=i;
	for(long long i=1;i<=n;++i)if(!mp[b[i]])return 0;
	return 1;
}
map<long long,long long>da[110],db[110];
void divi(long long x,map<long long,long long>&mp)
{
	for(long long i=1;su[i]*su[i]<=x;++i)
		if(x%su[i]==0)
		{
			long long cnt=0;
			while(x%su[i]==0)++cnt,x/=su[i];
			mp[su[i]]=cnt;
		}
	if(x>1)mp[x]=1;
}
void work(long long w)
{
	for(long long i=1;i<=n;++i)
	{
		long long c=a[i];
		while(c<w)c*=b[i];
		if(c!=w)no();
	}
	printf("%lld",w);
	exit(0);
}
void work1(long long A,long long B,long long N)
{
	if(N<0)no();
	map<long long,long long>dw,dA,dB,dC;
	divi(A,dA),divi(B,dB);
	dw=dA;
	for(auto p:dB)dw[p.first]+=N*p.second;
	for(long long i=1;i<=n;++i)
	{
		dC=da[i];
		for(auto p:dw)dC[p.first];
		for(auto p:dC)
			if(p.second!=dw[p.first])
			{
				if(!db[i][p.first])no();
				long long c=(dw[p.first]-p.second)/db[i][p.first];
		//		printf("%lld %lld\n",i,c);
				if(c<0)no();
			//	printf("%d %d\n",i,c);
				for(auto q:db[i])dC[q.first]+=q.second*c;
				break;
			}
		for(auto p:dC)if(p.second!=dw[p.first])no();
	}
	long long ans=1;
	for(auto p:dw)ans=ans*kpow(p.first,p.second)%mod;
	printf("%lld",ans);
	exit(0);
}
long long gcd(long long a,long long b)
{
	if(!a||!b)return a+b;
	return gcd(b,a%b);
}
long long exgcd(long long a,long long b,long long &x,long long &y)
{
	if(!b){x=1,y=0;return a;}
	if(!a){x=0,y=1;return b;}
	long long g=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}
void solve1(long long s)
{
//	printf("?");
//	printf("%d\n",s);
	long long sa=0;
	long long k[110],t[110];
	for(long long i=1;i<=n;++i)
	{
		long long x=a[i];t[i]=0;k[i]=mp[b[i]];
		while(x%s==0)x/=s,++t[i];
		if(sa&&sa!=x)no();
		sa=x;
	}
	long long nk=1,nt=0,x,y,mx=0;
//	for(int i=1;i<=n;++i)printf("%lld %lld\n",k[i],t[i]);
//	printf("!");
	for(long long i=1;i<=n;++i)
	{
		long long g=exgcd(nk,k[i],x,y);
		y=-y;
		if((t[i]-nt)%g)
		{
		//	printf("%lld!%lld!%lld!%lld!%lld!",nk,nt,k[i],t[i],g);
			no();
		}
		long long w=(t[i]-nt)/g;
		if(w<0)x=-x,y=-y,w=-w;
		x=x%(k[i]/g)*(w%(k[i]/g))%(k[i]/g);
		if(x<0)x+=k[i]/g;
		nt=x*nk+nt;
		while(nt<t[i])nt+=nk;
		nk=nk*k[i]/g;
		mx=max(mx,nt);
	//	if(nt<0)while(1);
	//	printf("%lld %lld\n",nk,nt);
	}
//	printf("%lld\n",mx);
//	exit(0);
	work1(sa,s,nt);
}
void solve2()
{
	long long p;
	for(long long i=2;i<=n;++i)if(!mp[b[i]]){p=i;break;}
	for(auto q:db[1])if(!db[p].count(q.first))work1(a[1],b[1],(da[p][q.first]-da[1][q.first])/q.second);
	for(auto q:db[p])if(!db[1].count(q.first))work1(a[p],b[p],(da[1][q.first]-da[p][q.first])/q.second);
	long long a1=db[1].begin()->second,b1=-db[p].begin()->second,c1=da[p][db[1].begin()->first]-da[1][db[1].begin()->first];
	long long a2,b2,c2;
	for(auto q:db[1])
	{
		a2=q.second,b2=-db[p][q.first],c2=da[p][q.first]-da[1][q.first];
	//	printf("%d %d %d %d %d %d\n",a1,b1,c1,a2,b2,c2);
		if(a1*b2!=a2*b1)work1(a[1],b[1],(c1*b2-c2*b1)/(a1*b2-a2*b1));
	}
}
int main()
{
	init();
	scanf("%lld",&n);
	for(long long i=1;i<=n;++i)
	{
		scanf("%lld %lld",&a[i],&b[i]);
		divi(a[i],da[i]);divi(b[i],db[i]);
		mib=min(mib,b[i]);
	}
	if(mib==1)
	{
		for(long long i=1;i<=n;++i)if(b[i]==1){work(a[i]);break;}
		return 0;
	}
	long long g=0;
	for(auto p:db[1])g=gcd(g,p.second);
	long long s=1;
	for(auto p:db[1])
	{
		long long cnt=p.second/g;
		while(cnt--)s*=p.first;
	}
	if(check(s))solve1(s);
	else solve2();
	return 0;
}