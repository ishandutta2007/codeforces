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
 
inline int Abs(int a){return a>0?a:-a;};
inline int Min(int a,int b){return a>b?b:a;}
inline int Max(int a,int b){return a>b?a:b;}
 
const int N=2e5+5;
int t,n,a[N],val[N*4],suc[N],flag;
 
void build(int x,int l,int r);
int query(int x,int l,int r,int L,int R);
inline int binary1(int x,int p);
inline int binary2(int x,int l,int r);
 
signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
			a[i]=read();
		build(1,1,n);
		for(int i=n;i>=1;--i)
			suc[i]=max(suc[i+1],a[i]);
		int now=0;flag=0;
		for(int i=1;i<=n;++i)
		{
			now=max(now,a[i]);
			int pos1=binary1(now,i+1)+1;
			int pos2=binary1(now+1,i+1)+2;
			if(pos1==-1) continue;
			if(pos2==0) pos2=i+2;
			if(pos1>n) pos1=n; 
			if(pos2>n) pos2=n;
			int pos3=binary2(now,pos2,pos1);
			if(pos3==-1) continue;
			if(i<=0||pos3-1-i<=0||n-(pos3-1-i)-i<=0) continue;
			if(suc[pos3]!=now||query(1,1,n,i+1,pos3-1)!=now)
				continue;
			printf("YES\n%lld %lld %lld\n",i,pos3-1-i,n-(pos3-1-i)-i);
			flag=1;break;
		}
		if(flag==0) printf("NO\n");
		for(int i=1;i<=n;++i)
			suc[i]=0;
	}
	return 0;
}
 
void build(int x,int l,int r)
{
	if(l==r)
	{
		val[x]=a[l];
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	val[x]=min(val[lc],val[rc]);
}
 
int query(int x,int l,int r,int L,int R)
{
	if(L<=l&&r<=R) return val[x];
	int res=1e18;
	if(L<=mid) res=min(res,query(lc,l,mid,L,R));
	if(mid+1<=R) res=min(res,query(rc,mid+1,r,L,R));
	return res;
}
 
inline int binary1(int x,int p)
{
	int l=p,r=n,res=-2;
	while(l<=r)
	{
		if(query(1,1,n,p,mid)>=x)
		{
			res=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return res;
}
 
inline int binary2(int x,int l,int r)
{
	int res=-1;
	while(l<=r)
	{
		if(suc[mid]<=x)
		{
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return res;
}