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
#define lowbit(x) (x&(-x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
#define max Max
#define min Min
#define abs Abs

using namespace std;

inline int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=(ans<<1)+(ans<<3)+c-'0';c=getchar();}
	return ans*f;
}

inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x/10) write(x/10);
	putchar((char)(x%10)+'0');
}

template<typename T>inline T Abs(T a){return a>0?a:-a;};
template<typename T,typename TT>inline T Min(T a,TT b){return a>b?b:a;}
template<typename T,typename TT> inline T Max(T a,TT b){return a>b?a:b;}

const int N=2005;
int t,n,firh[N][10],enh[N][10],firl[N][10],enl[N][10];
char s[N][N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			for(int j=0;j<=9;++j)
			{
				firh[i][j]=-1;enh[i][j]=-1;
				firl[i][j]=-1;enl[i][j]=-1;
			}
		for(int i=1;i<=n;++i)
			scanf("%s",s[i]+1);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
			{
				if(firh[i][s[i][j]-'0']==-1)
					firh[i][s[i][j]-'0']=j;
				enh[i][s[i][j]-'0']=j;
			}
		for(int j=1;j<=n;++j)
			for(int i=1;i<=n;++i)
			{
				if(firl[j][s[i][j]-'0']==-1)
					firl[j][s[i][j]-'0']=i;
				enl[j][s[i][j]-'0']=i;
			}
		for(int p=0;p<=9;++p)
		{
			int res=0;
			int mmax=-1,mmin=1e18;
			for(int i=1;i<=n;++i)
			{
				if(enl[i][p]!=-1) mmax=max(mmax,enl[i][p]);
				if(firl[i][p]!=-1) mmin=min(mmin,firl[i][p]);
			}
			for(int i=1;i<=n;++i)
			{
				if(mmax!=-1&&firh[i][p]!=-1) res=max(res,abs(firh[i][p]-n)*abs(i-mmax));
				if(mmin!=1e18&&firh[i][p]!=-1) res=max(res,abs(firh[i][p]-n)*abs(i-mmin));
				if(mmax!=-1&&enh[i][p]!=-1) res=max(res,(enh[i][p]-1)*abs(i-mmax));
				if(mmin!=1e18&&enh[i][p]!=-1) res=max(res,(enh[i][p]-1)*abs(i-mmin));
				if(firh[i][p]!=-1&&enh[i][p]!=-1) res=max(res,abs(firh[i][p]-enh[i][p])*abs(i-n));
				if(firh[i][p]!=-1&&enh[i][p]!=-1) res=max(res,abs(firh[i][p]-enh[i][p])*abs(i-1));
			}
			mmax=0,mmin=1e18;
			for(int i=1;i<=n;++i)
			{
				if(enh[i][p]!=-1) mmax=max(mmax,enh[i][p]);
				if(firh[i][p]!=-1) mmin=min(mmin,firh[i][p]);
			}
			for(int i=1;i<=n;++i)
			{
				if(mmax!=-1&&firl[i][p]!=-1) res=max(res,abs(firl[i][p]-n)*abs(i-mmax));
				if(mmin!=1e18&&firl[i][p]!=-1) res=max(res,abs(firl[i][p]-n)*abs(i-mmin));
				if(mmax!=-1&&enl[i][p]!=-1) res=max(res,(enl[i][p]-1)*abs(i-mmax));
				if(mmin!=1e18&&enl[i][p]!=-1) res=max(res,(enl[i][p]-1)*abs(i-mmin));
				if(firl[i][p]!=-1&&enl[i][p]!=-1) res=max(res,abs(firl[i][p]-enl[i][p])*abs(i-n));
				if(firl[i][p]!=-1&&enl[i][p]!=-1) res=max(res,abs(firl[i][p]-enl[i][p])*abs(i-1));
			}
			printf("%lld ",res);
		}
		printf("\n");
	}
	return 0;
}