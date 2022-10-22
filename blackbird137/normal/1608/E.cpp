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

const int N=1e5+5;
int n,nn[3],c[3];

struct Node
{
	int x,y;
}a[3][N],b[3][N];

inline bool cmp1(Node a,Node b)
{
	return a.x<b.x;
}

inline bool cmp2(Node a,Node b)
{
	return a.y<b.y;
}

inline bool check(int x)
{
	for(int i=0;i<=2;++i)
		c[i]=i;
	do
	{
		int now=-2e9;
		for(int i=0;i<=2;++i)
		{
			int ss=0,ne=-2e9;
			for(int j=1;j<=n/3;++j)
			{
				if(a[c[i]][j].x>now) ++ss;
				if(ss==x){ne=a[c[i]][j].x;break;}
			}
			if(ne==-2e9)
				break;
			if(i==2) return 1;
			now=ne;
		}
		now=-2e9;
		for(int i=0;i<=2;++i)
		{
			int ss=0,ne=-2e9;
			for(int j=1;j<=n/3;++j)
			{
				if(b[c[i]][j].y>now) ++ss;
				if(ss==x){ne=b[c[i]][j].y;break;}
			}
			if(ne==-2e9)
				break;
			if(i==2) return 1;
			now=ne;
		}
		int s2=0,s3=0;
		int l1=-2e9,l2=-2e9;
		l1=a[c[0]][x].x;
		for(int i=1;i<=n/3;++i)
		{
			if(b[c[1]][i].x>l1) s2++;
			if(s2==x) {l2=b[c[1]][i].y;break;}
		}
		if(l2!=-2e9)
		{
			for(int i=1;i<=n/3;++i)
				if(a[c[2]][i].x>l1&&a[c[2]][i].y>l2)
					s3++;
			if(s3>=x) return 1;
		}
		
		s2=0;s3=0;
		l1=2e9;l2=-2e9;
		l1=b[c[0]][n/3-x+1].y;
		for(int i=1;i<=n/3;++i)
		{
			if(a[c[1]][i].y<l1) s2++;
			if(s2==x) {l2=a[c[1]][i].x;break;}
		}
		if(l2!=-2e9)
		{
			for(int i=1;i<=n/3;++i)
				if(a[c[2]][i].x>l2&&a[c[2]][i].y<l1)
					s3++;
			if(s3>=x) return 1;
		}
		
		s2=0;s3=0;
		l1=2e9;l2=2e9;
		l1=a[c[0]][n/3-x+1].x;
		for(int i=n/3;i>=1;--i)
		{
			if(b[c[1]][i].x<l1) s2++;
			if(s2==x) {l2=b[c[1]][i].y;break;}
		}
		if(l2!=2e9)
		{
			for(int i=1;i<=n/3;++i)
				if(a[c[2]][i].x<l1&&a[c[2]][i].y<l2)
					s3++;
			if(s3>=x) return 1;
		}
		
		s2=0;s3=0;
		l1=-2e9;l2=2e9;
		l1=b[c[0]][x].y;
		for(int i=n/3;i>=1;--i)
		{
			if(a[c[1]][i].y>l1) s2++;
			if(s2==x) {l2=a[c[1]][i].x;break;}
		}
		if(l2!=2e9)
		{
			for(int i=1;i<=n/3;++i)
				if(a[c[2]][i].x<l2&&a[c[2]][i].y>l1)
					s3++;
			if(s3>=x) return 1;
		}
	}while(next_permutation(c,c+3));
	return 0;
}

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	{
		int x=read(),y=read(),c=read()-1;
		++nn[c];a[c][nn[c]]=b[c][nn[c]]=(Node){x,y};
	}
	for(int i=0;i<=2;++i)
	{
		sort(a[i]+1,a[i]+1+n/3,cmp1);
		sort(b[i]+1,b[i]+1+n/3,cmp2);
	}
	int l=1,r=n/3,ps=0;
	while(l<=r)
	{
		if(check(mid))
			ps=mid,l=mid+1;
		else r=mid-1;
	}
	write(ps*3);
	return 0;
}