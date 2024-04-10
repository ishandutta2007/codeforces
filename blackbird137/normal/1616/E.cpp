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

const int N=1e5+5;
int t,n,ps[30],hav[30][N],tot[30],now[30],to[N];
char s1[N],s2[N];

struct BIT
{
	int c[N];
	inline void add(int x,int v)
	{
		for(;x<=n;x+=lowbit(x))
			c[x]+=v;
	}
	inline void update(int l,int r,int v)
	{
		add(l,v);add(r+1,-v);
	}
	inline int query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))
			res+=c[x];
		return res;
	}
	inline void clear()
	{
		for(int i=1;i<=n;++i)
			c[i]=0;
	}
}sum;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		scanf("%s",s1+1);
		scanf("%s",s2+1);
		for(int i=0;i<26;++i)
			tot[i]=0,now[i]=1;
		for(int i=1;i<=n;++i)
			hav[s1[i]-'a'][++tot[s1[i]-'a']]=i;
		int ans=1e18,qwq=0;
		for(int i=1;i<=n;++i)
		{
			int j=s2[i]-'a';
			for(int k=0;k<j;++k)
				if(now[k]<=tot[k])
					ans=min(ans,qwq+hav[k][now[k]]+sum.query(hav[k][now[k]])-i);
			if(now[j]>tot[j])
				break;
			else
			{
				int x=hav[j][now[j]++];
				qwq+=x+sum.query(x)-i;
				sum.update(1,x,1);
			}
		}
		if(ans==1e18) puts("-1");
		else write(ans),puts("");
		sum.clear();
	}
	return 0;
}