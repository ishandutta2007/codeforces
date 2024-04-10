#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<ctime>
#include<queue>
#include<map>
#include<set>

#define ll long long
#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;

namespace fastIO
{
    #define BUF_SIZE 100000
    bool IOerror=0;
    inline char nc()
	{
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE;
        if(p1==pend)
		{
            p1=buf;
            pend=buf+fread(buf,1,BUF_SIZE,stdin);
            if(pend==p1)
			{
                IOerror=1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch)
	{
        return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';
    }
    inline ll read()
	{
		ll ans=0,f=1;
		char c=nc();
		while(c>'9'||c<'0'){if(c=='-')f=-1;c=nc();}
		while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=nc();}
		return ans*f;
	}
    #undef BUF_SIZE
};

using namespace fastIO;

inline void write(ll x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1e6+5;
ll n,a[N],sm[N],ans;
int nm[N][62];

inline ll count(ll x)
{
	ll res=0;
	for(ll i=0;i<60;++i)
		if((x>>i)&1)
			res++;
	return res;
}

inline void solve(ll l,ll r)
{
	if(l==r)
	{
		ans++;
		return;
	}
	solve(l,mid);
	solve(mid+1,r);
	//part1:mx,mn
	//part3:mxmn
	//part4:mnmx
	//ll st=ans;
	for(ll i=mid;i<=r;++i)
		for(ll j=0;j<60;++j)
			nm[i][j]=0;
	ll mmn=2e18,pps=-1;
	for(ll i=mid+1;i<=r;++i)
	{
		if(a[i]<mmn)
			mmn=a[i],pps=i;
		for(ll j=0;j<60;++j)
			nm[i][j]=nm[i-1][j];
		nm[i][sm[pps]]++;
	}
	ll mx=-2e18,ps1=-1,mn=2e18,ps2=-1,j1=mid,j2=mid;
	for(ll i=mid;i>=l;--i)
	{
		if(a[i]>mx)
		{
			mx=a[i];ps1=i;
			while(j1+1<=r&&a[j1+1]<=mx)
				++j1;
		}
		if(a[i]<mn)
		{
			mn=a[i];ps2=i;
			while(j2+1<=r&&a[j2+1]>=mn)
				++j2;
		}
		ll tmp=min(j1,j2);
		tmp=tmp-mid;
		if(sm[ps1]==sm[ps2])
			ans+=tmp;
		if(j2+1<=j1)
			ans+=nm[j1][sm[ps1]]-nm[j2][sm[ps1]];
	}
	
	//part4:mnmx
	for(ll i=mid;i<=r;++i)
		for(ll j=0;j<60;++j)
			nm[i][j]=0;
	mmn=-2e18,pps=-1;
	for(ll i=mid+1;i<=r;++i)
	{
		if(a[i]>mmn)
			mmn=a[i],pps=i;
		for(ll j=0;j<60;++j)
			nm[i][j]=nm[i-1][j];
		nm[i][sm[pps]]++;
	}
	mx=-2e18,ps1=-1,mn=2e18,ps2=-1,j1=mid,j2=mid;
	for(ll i=mid;i>=l;--i)
	{
		if(a[i]>mx)
		{
			mx=a[i];ps1=i;
			while(j1+1<=r&&a[j1+1]<=mx)
				++j1;
		}
		if(a[i]<mn)
		{
			mn=a[i];ps2=i;
			while(j2+1<=r&&a[j2+1]>=mn)
				++j2;
		}
		if(j1+1<=j2)
			ans+=nm[j2][sm[ps2]]-nm[j1][sm[ps2]];
	}
	//part2:mx,mn 
	mx=-2e18,ps1=-1,mn=2e18,ps2=-1,j1=mid+1,j2=mid+1;
	for(ll i=mid+1;i<=r;++i)
	{
		if(a[i]>mx)
		{
			mx=a[i];ps1=i;
			while(j1-1>=l&&a[j1-1]<mx)
				--j1;
		}
		if(a[i]<mn)
		{
			mn=a[i];ps2=i;
			while(j2-1>=l&&a[j2-1]>mn)
				--j2;
		}
		ll tmp=max(j1,j2);
		tmp=mid-tmp+1;
		if(sm[ps1]==sm[ps2])
			ans+=tmp;
	}
	//printf("%lld %lld %lld\n",l,r,ans-st);
}

signed main()
{
	
	n=read();
	for(ll i=1;i<=n;++i)
	{
		a[i]=read();
		sm[i]=count(a[i]);
	}
	solve(1,n);
	write(ans);
	return 0;
}