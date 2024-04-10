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

const int N=1e5+5;
int t,n,q,a[N];

struct Node
{
	int v[35];
	Node ()
	{
		for(int i=0;i<=33;++i)
			v[i]=-1;
	}
	Node operator + (const Node &x)const
	{
		Node res;
		for(int i=0,j=0,k=0;k<=33;)
		{
			int p1=(i>33||v[i]==-1);
			int p2=(j>33||x.v[j]==-1); 
			if(p1&&p2) break;
			else if(p1) res.v[k++]=x.v[j++];
			else if(p2) res.v[k++]=v[i++];
			else if(x.v[j]<v[i]) res.v[k++]=x.v[j++];
			else res.v[k++]=v[i++];
		}
		return res;
	}
};

struct Seg
{
	Node val[N<<2];
	void build(int x,int l,int r)
	{
		if(l==r)
		{
			Node tmp;
			tmp.v[0]=a[l];
			val[x]=tmp;
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		val[x]=val[lc]+val[rc];
	}
	Node query(int x,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return val[x];
		if(L<=mid&&mid+1<=R)
			return query(lc,l,mid,L,R)+query(rc,mid+1,r,L,R);
		else if(L<=mid) return query(lc,l,mid,L,R);
		else return query(rc,mid+1,r,L,R);
	}
}sum;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		q=read();
		sum.build(1,1,n);
		while(q--)
		{
			int l=read(),r=read();
			Node res=sum.query(1,1,n,l,r);
			int ans=INF;
			for(int i=0;i<=33;++i)
				for(int j=i+1;j<=33;++j)
					if(res.v[j]!=-1)
						ans=min(ans,res.v[i]|res.v[j]);
			write(ans);puts("");
		}
	}
	return 0;
}