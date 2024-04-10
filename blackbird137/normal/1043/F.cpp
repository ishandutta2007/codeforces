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

#define fi first
#define se second
#define max Max
#define min Min
#define abs Abs
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

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

const int N=4e6+5,M=4e6;
int n,m,mm,a[N],b[N],sm[N],nm[N],g,p[15],ans=INF;
int pri[N],vis[N],hav[N],pw[200];
int in[200],dp[200],mul[200];
unsigned char cnt[N];

inline void init(int x)
{
	for(int i=2;i<=x;++i)
	{
		if(!vis[i])
			pri[++m]=i;
		for(int j=1;j<=m;++j)
		{
			if(i*pri[j]>x)
				break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)
				break;
		}
	}
}

int yz[N][8];

signed main()
{
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),g=__gcd(g,a[i]);
	if(g!=1)
	{
		puts("-1");
		return 0;
	}
	int sum=0;
	for(int i=1;i<=n;++i)
		if(a[i]==g) ++sum;
	if(sum!=0)
	{
		write(1);
		return 0;
	}
	for(int i=1;i<=n;++i)
		a[i]/=g,mm=max(mm,a[i]);
	mm=M;
	sort(a+1,a+1+n);
	int nnn=n;
	n=unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=n;++i)
		b[a[i]]=1;
	for(int i=1;i<=mm;++i)
		for(int j=i;j<=mm;j+=i)
			sm[i]+=b[j];
	for(int i=1;i<=mm;++i)
		hav[i]=-sm[i];
	init(mm);
	for(int i=1;i<=m;++i)
		for(int j=pri[i];j<=mm;j+=pri[i])
			hav[j]-=hav[j/pri[i]];
	hav[1]=sm[1];
	for(int i=1;i<=m;++i)
		yz[pri[i]][cnt[pri[i]]++]=pri[i];
	for(int i=1,j=0;j<=7;i<<=1,++j)
		pw[i]=j;
	for(int i=2;i<=mm;++i)
	{
		for(int j=0;j<cnt[i];++j)
			if(i+yz[i][j]<=mm)
				yz[i+yz[i][j]][cnt[i+yz[i][j]]++]=yz[i][j];
		if(!b[i]) continue;
		int nn=cnt[i];
		for(int j=0;j<(1<<nn);++j)
			in[j]=0,dp[j]=INF,mul[j]=1;
		for(int j=1;j<(1<<nn);++j)
		{
			int ps=pw[lowbit(j)];
			mul[j]=yz[i][ps]*mul[j^lowbit(j)];
			in[j]=(hav[mul[j]]!=0);
		}
		in[0]=1;dp[0]=1;
		for(int j=0;j<nn;++j)
			for(int k=0;k<(1<<nn);++k)
				if(!((k>>j)&1)) in[k]|=in[k^(1<<j)];
		for(int j=1;j<(1<<nn);++j)
			for(int k=j;k;k=(j&(k-1)))
				if(in[k]) dp[j]=min(dp[j],dp[j^k]+1);
		ans=min(ans,dp[(1<<nn)-1]);
		if(ans==2) break;
	}
	write(ans);
	return 0;
}