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

const int N=3e5+5;
int n,m,a[N],b[N],c[N],rk[N],I;
char s[N];

inline bool cmp(int x,int y)
{
	if(rk[x]==rk[y])
		return rk[x^I]<rk[y^I];
	return rk[x]<rk[y];
}

signed main()
{
	n=read();
	scanf("%s",s);
	for(int i=0;i<(1<<n);++i)
		a[++m]=s[i]-'a';
	sort(a+1,a+1+m);
	m=unique(a+1,a+1+m)-a-1;
	for(int i=0;i<(1<<n);++i)
		rk[i]=lower_bound(a+1,a+1+m,s[i]-'a')-a;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<(1<<n);++j)
			b[j]=j;
		I=(1<<(i-1));
		sort(b,b+(1<<n),cmp);
		c[b[0]]=1;
		for(int j=1;j<(1<<n);++j)
			c[b[j]]=c[b[j-1]]+cmp(b[j-1],b[j]);
		for(int j=0;j<(1<<n);++j)
			rk[j]=c[j];
	}
	int ps=-1;
	for(int i=0;i<(1<<n);++i)
		if(rk[i]==1) ps=i;
	for(int i=0;i<(1<<n);++i)
		putchar(s[ps^i]);
	return 0;
}