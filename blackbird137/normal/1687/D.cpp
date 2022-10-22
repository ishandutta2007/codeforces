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

#define int long long
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
#define INF 0x3f3f3f3f3f3f3f3f

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

const int N=3e6+5;
int n,a[N],fa[N];

vector<int> hv[N];

inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

inline bool ck(int x)
{
	int l=(int)sqrt(x);
	return x>=l*l&&x<=l*l+l;
}

inline int check(int x)
{
	int l=0,r=INF;
	for(int L=1,R;L<=n;L=R+1)
	{
		R=find(L);
		if(L==1)
		{
			l=max(l,x*x-a[L]);
			r=min(r,x*x+x-a[R]);
		}
		else
		{
			if(!ck(a[L]+l))
			{
				int tmp=(int)sqrt(a[L]+l)+1;
				l=max(l,tmp*tmp-a[L]);
			}
			int ps=(int)sqrt(a[L]+l);
			r=min(r,ps*ps+ps-a[R]);
		}
		if(l>r) return -1;
	}
	return l;
}

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();fa[i]=i;
		if(i!=1) hv[a[i]-a[i-1]].push_back(i);
	}
	for(int i=0;i<hv[0].size();++i)
		fa[find(hv[0][i]-1)]=find(hv[0][i]);
	int ans=INF;
	for(int i=1;i<=a[n];++i)
	{
		for(int j=0;j<hv[i].size();++j)
			fa[find(hv[i][j]-1)]=find(hv[i][j]);
		int tmp=check(i);
		if(tmp!=-1) ans=min(ans,tmp);
	}
	write(ans);
	return 0;
}