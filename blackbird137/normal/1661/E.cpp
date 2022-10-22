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

const int N=5e5+5;
int n,q,a[5][N];
char s[N];

struct DSU
{
	int fa[15];
	int find(int x)
	{
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	bool merge(int x,int y)
	{
		int f1=find(x),f2=find(y);
		if(f1==f2) return 0;
		fa[f1]=f2;return 1;
	}
};

struct Node
{
	int fa[8],l,r,val;
	inline int find(int x)
	{
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	Node operator + (const Node &x)const
	{
		Node res;
		res.l=l;res.r=x.r;
		res.val=val+x.val;
		DSU tmp,tmp2;
		for(int i=1;i<=6;++i) tmp.fa[i]=fa[i];
		for(int i=1;i<=6;++i) tmp.fa[i+6]=x.fa[i]+6;
		if(a[1][r]==0&&a[1][x.l]==0) res.val-=tmp.merge(4,7);
		if(a[2][r]==0&&a[2][x.l]==0) res.val-=tmp.merge(5,8);
		if(a[3][r]==0&&a[3][x.l]==0) res.val-=tmp.merge(6,9);
		for(int i=1;i<=6;++i)
			tmp2.fa[i]=i;
		for(int i=1;i<=6;++i)
			for(int j=i+1;j<=6;++j)
			{
				int p1=(i<=3?i:i+6);
				int p2=(j<=3?j:j+6);
				if(tmp.find(p1)==tmp.find(p2))
					tmp2.merge(i,j);
			}
		for(int i=1;i<=6;++i)
			res.fa[i]=tmp2.fa[i];
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
			val[x].l=l;val[x].r=r;
			DSU tmp;val[x].val=3;
			val[x].val-=a[1][l]+a[2][l]+a[3][l];
			for(int i=1;i<=3;++i)
				tmp.fa[i]=i,tmp.fa[i+3]=i;
			for(int i=1;i<=2;++i)
				if(a[i][l]==0&&a[i+1][l]==0)
					tmp.merge(i,i+1),val[x].val--;
			for(int i=1;i<=6;++i)
				val[x].fa[i]=tmp.fa[i];
			return;
		}
		build(lc,l,mid);
		build(rc,mid+1,r);
		val[x]=val[lc]+val[rc];
	}
	Node query(int x,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
			return val[x];
		if(L<=mid&&mid+1<=R)
			return query(lc,l,mid,L,R)+query(rc,mid+1,r,L,R);
		else if(L<=mid) return query(lc,l,mid,L,R);
		else return query(rc,mid+1,r,L,R);
	}
}sum;

signed main()
{
	n=read();
	for(int i=1;i<=3;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=n;++j)
			a[i][j]=1-s[j]+'0';
	}
	q=read();
	sum.build(1,1,n);
	while(q--)
	{
		int l=read(),r=read();
		Node ans=sum.query(1,1,n,l,r);
		write(ans.val);puts("");
	}
	return 0;
}