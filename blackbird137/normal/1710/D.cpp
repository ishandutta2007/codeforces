#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<random>
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
#define lowbit(x) ((x)&(-(x)))
#define fan(x) ((((x)-1)^1)+1)
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

const int N=2e3+5;
int t,n,a[N][N],l[N],r[N],ls[2];
char s[N][N];

vector<pair<int,int> > ans;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			scanf("%s",s[i]+1);
		for(int i=1;i<=n;++i)
			for(int j=i;j<=n;++j)
				a[i][j]=s[i][j-i+1]-'0';
		for(int i=1;i<=n;++i)
			l[i]=r[i]=i;
		for(int L=2;L<=n;++L)
			for(int i=1;i+L-1<=n;++i)
			{
				int j=i+L-1;
				if(a[i][j]&&(l[i]!=l[j]||r[i]!=r[j]))
				{
					ans.push_back(mp(i,j));
					ls[0]=i;ls[1]=j;int now=1;
					for(int k=r[i]+1;k<l[j];k=r[k]+1)
					{
						ans.push_back(mp(ls[now],k));
						ls[now]=k;now^=1;
					}
					int ll=l[i],rr=r[j];
					for(int k=l[i];k<=r[j];++k)
						l[k]=ll,r[k]=rr;
				}
			}
		for(auto i:ans)
			write(i.fi),putchar(' '),write(i.se),puts("");
		ans.clear();
	}
	return 0;
}