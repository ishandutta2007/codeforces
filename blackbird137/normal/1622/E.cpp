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
#define lowbit(x) (x&(-x))
#define fan(x) (((x-1)^1)+1)
#define mp(x,y) make_pair(x,y)
#define clr(f,n) memset(f,0,sizeof(int)*(n))
#define cpy(f,g,n) memcpy(f,g,sizeof(int)*(n))
#define INF 0x3f3f3f3f

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
template<typename T,typename TT>inline T Min(T a,TT b){return a<b?a:b;}
template<typename T,typename TT> inline T Max(T a,TT b){return a<b?b:a;}

const int N=1e4+5;
int t,n,m,a[N],c[N],ans;
char s[15][N];

pair<int,int> b[N];

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=1;i<=n;++i)
			scanf("%s",s[i]+1);
		ans=-1e9;
		for(int i=0;i<(1<<n);++i)
		{
			for(int j=1;j<=m;++j)
			{
				b[j]=mp(0,j);
				for(int k=1;k<=n;++k)
					if(s[k][j]=='1')
					{
						if((i>>(k-1))&1)
							b[j].fi++;
						else b[j].fi--;
					}
			}
			sort(b+1,b+1+m);
			int tmp=0;
			for(int j=1;j<=n;++j)
				if((i>>(j-1))&1)
					tmp-=a[j];
				else tmp+=a[j];
			for(int j=1;j<=m;++j)
				tmp+=j*b[j].fi;
			if(tmp>ans)
			{
				ans=tmp;
				for(int j=1;j<=m;++j)
					c[b[j].se]=j;
			}
		}
		for(int i=1;i<=m;++i)
			write(c[i]),putchar(' ');
		puts("");
	}
	return 0;
}