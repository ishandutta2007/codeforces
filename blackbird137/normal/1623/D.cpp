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

#define int long long
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
    inline int read()
	{
		int ans=0,f=1;
		char c=nc();
		while(c>'9'||c<'0'){if(c=='-')f=-1;c=nc();}
		while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=nc();}
		return ans*f;
	}
    #undef BUF_SIZE
};

using namespace fastIO;

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

#define id(x,y) ((((x)-1)*m)+(y))

const int N=6e5+5,mod=1e9+7;
int t,n,m,k,sx,sy,ex,ey,vis[N],a[N];

inline int q_pow(int a,int b)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%mod;
		a=a*a%mod;b>>=1;
	}
	return c;
}

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();k=0;
		sx=read();sy=read();
		ex=read();ey=read();
		int dx=1,dy=1,p=read();
		int stx=sx,sty=sy,fl=1,stdx=1,stdy=1;
		if(sx+dx<1||sx+dx>n) stdx=-1;
		if(sy+dy<1||sy+dy>m) stdy=-1;
		while(1)
		{
			if(sx+dx<1||sx+dx>n) dx=-dx;
			if(sy+dy<1||sy+dy>m) dy=-dy;
			if(sx==stx&&sy==sty&&sx+dx==stx+stdx&&sy+dy==sty+stdy&&!fl) break;
			a[++k]=(sx==ex||sy==ey);
			sx+=dx;sy+=dy;fl=0;
		}
		p=p*q_pow(100,mod-2)%mod;
		int tmp=0,ans=0;
		for(int i=1;i<=k;++i)
			if(a[i]) ++tmp;
		int tmp2=(1-p+mod)%mod;
		tmp=q_pow(tmp2,tmp);
		tmp=q_pow((1-tmp+mod)%mod,mod-2)%mod;
		int now=1;
		for(int i=1;i<=k;++i)
			if(a[i])
			{
				ans=(ans+now*p%mod*i%mod*tmp%mod)%mod;
				now=now*tmp2%mod;
			}
		ans=(ans+(tmp-1+mod)%mod*k%mod)%mod;
		write((ans-1+mod)%mod);puts("");
		for(int i=1;i<=n*m;++i)
			vis[i]=0;
	}
	return 0;
}