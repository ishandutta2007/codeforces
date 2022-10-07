#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int N=200005,E=524288;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	template <class I>
	inline void gi (I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	// print a signed integer
	template <class I>
	inline void print (I x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: gi;
using io :: putc;
using io :: print;
int n,m,p,t,l,r,x;
int i,j,lazy[N*4],a[N*2],lazya[N*4];
struct str{
	int x,y;
}tmp[15];
struct vc{
	int k;
	str x[6];
	void push_back(str p)
	{
		x[k++]=p;
	}
	void clear()
	{
		k=0;
	}
};
vc tree[N*4];
bool cmp(str a,str b)
{
	return a.x<b.x;
}
vc Merge(vc a,vc b)
{
	vc ans;
	ans.k=0;
	int l=0,k=0,i,j;
	for(i=0;i<a.k;++i)
		tmp[++l]=a.x[i];
	for(i=0;i<b.k;++i)
		tmp[++l]=b.x[i];
	sort(tmp+1,tmp+1+l,cmp);
	for(i=1;i<=l;)
	{
		int s=0;
		for(j=i;j<=l&&tmp[i].x==tmp[j].x;++j)
			s+=tmp[j].y;
		tmp[++k]=(str){tmp[i].x,s};
		i=j;
	}
	l=k;
	while(l>p)
	{
		int mn=(1<<30);
		for(j=1;j<=p+1;++j)
			mn=min(mn,tmp[j].y);
		for(j=1;j<=p+1;++j)
			tmp[j].y-=mn;
		for(j=1;j<=l;++j)
			if(tmp[j].y==0)
				break;
		for(;j<l;++j)
			tmp[j]=tmp[j+1];
		--l;
	}
	for(j=1;j<=l;++j)
		ans.push_back(tmp[j]);
	return ans;
}
void pushup(int i)
{
	tree[i]=Merge(tree[i<<1],tree[i<<1|1]);
}
void pda(int i)
{
	lazya[i<<1]+=lazya[i];
	lazya[i<<1|1]+=lazya[i];
	for(int j=0;j<tree[i<<1].k;++j)
		tree[i<<1].x[j].x+=lazya[i];
	for(int j=0;j<tree[i<<1|1].k;++j)
		tree[i<<1|1].x[j].x+=lazya[i];
	lazya[i]=0;
}
void pd(int i,int l,int r)
{
	if(lazy[i])
	{
		lazy[i<<1]=lazy[i];
		lazy[i<<1|1]=lazy[i];
		int mid=l+r>>1;
		tree[i<<1].clear();
		tree[i<<1].push_back((str){lazy[i],mid-l+1});
		tree[i<<1|1].clear();
		tree[i<<1|1].push_back((str){lazy[i],r-mid});
		lazya[i<<1]=lazya[i<<1|1]=lazy[i]=0;
	}
}
void pushdown(int i,int l,int r)
{
	pd(i,l,r);
	pda(i);
}
void modify(int i,int l,int r,int ll,int rr,int x)
{
	if(l>=ll&&r<=rr)
	{
		lazy[i]=x;
		lazya[i]=0;
		tree[i].clear();
		tree[i].push_back((str){x,r-l+1});
		return;
	}
	pushdown(i,l,r);
	int mid=l+r>>1;
	if(mid>=ll)
		modify(i<<1,l,mid,ll,rr,x);
	if(mid<rr)
		modify(i<<1|1,mid+1,r,ll,rr,x);
	pushup(i);
}
void modify2(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
	{
		int j;
		++lazya[i];
		for(j=0;j<tree[i].k;++j)
			++tree[i].x[j].x;
		return;
	}
	pushdown(i,l,r);
	int mid=l+r>>1;
	if(mid>=ll)
		modify2(i<<1,l,mid,ll,rr);
	if(mid<rr)
		modify2(i<<1|1,mid+1,r,ll,rr);
	pushup(i);
}
vc Query(int i,int l,int r,int ll,int rr)
{
	if(l>=ll&&r<=rr)
		return tree[i];
	int mid=l+r>>1;
	pushdown(i,l,r);
	if(mid>=ll&&mid<rr)
		return Merge(Query(i<<1,l,mid,ll,rr),Query(i<<1|1,mid+1,r,ll,rr));
	if(mid>=ll)
		return Query(i<<1,l,mid,ll,rr);
	if(mid<rr)
		return Query(i<<1|1,mid+1,r,ll,rr);
}
void Build(int i,int l,int r)
{
	if(l==r)
	{
		tree[i].push_back((str){a[l],1});
		return;
	}
	int mid=l+r>>1;
	Build(i<<1,l,mid);
	Build(i<<1|1,mid+1,r);
	pushup(i);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	gi(n),gi(m),gi(p);
	p=100/p;
	for(i=1;i<=n;++i)
		gi(a[i]);
	Build(1,1,n);
	while(m--)
	{
		gi(t),gi(l),gi(r);
		if(t==1)
		{
			gi(x);
			modify(1,1,n,l,r,x);
		}
		if(t==2)
		{
			vc ans=Query(1,1,n,l,r);
			print(ans.k);
			for(i=0;i<ans.k;++i)
			{
				putc(' ');
				print(ans.x[i].x);
			}
			putc('\n');
		}
	}
}