#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int BUF_SIZE=1<<22;
char BUF_R[BUF_SIZE],*csy1,*csy2;
#define GC (csy1==csy2&&(csy2=(csy1=BUF_R)+fread(BUF_R,1,BUF_SIZE,stdin),csy1==csy2)?EOF:*csy1++)

template <class T>
inline void RI(T &t)
{
	char c=GC;
	for (t=0;c<48||c>57;c=GC);
	for (;c>47&&c<58;c=GC) t=(t<<1)+(t<<3)+c-48;
}

template <class T,typename ... Args>
inline void RI(T &t,Args&... args)
{
	RI(t);RI(args...);
}

char BUF_W[BUF_SIZE],*csy=BUF_W;
inline void WC(const char &c)
{
	if (csy-BUF_W==BUF_SIZE) fwrite(BUF_W,1,BUF_SIZE,stdout),csy=BUF_W;
	*csy++=c;
}

template <class T>
inline void WI(T x)
{
	static int IO_STACK[30],IO_TOP;
	if (x<0) {
		WC('-');
		do IO_STACK[IO_TOP++]=-(x%10); while (x/=10);
	}else {
		do IO_STACK[IO_TOP++]=x%10; while (x/=10);
	}
	while (IO_TOP) WC(IO_STACK[--IO_TOP]+48);
}

inline void IO_flush() {fwrite(BUF_W,1,csy-BUF_W,stdout);csy=BUF_W;}

const int Maxn=100005;
const int Maxm=1<<18;
const int mod=1e9+7;
inline int md(const int &a) {return a>mod?a-mod:a;}
int n,m,a[Maxn];
struct Matrix{
	int a,b;
	Matrix (int a_=1,int b_=1) : a(a_),b(b_) {}
	inline Matrix operator + (const Matrix &x)
	{
		return Matrix(md(a+x.a),md(b+x.b));
	}
	inline Matrix& operator *= (const Matrix &x)
	{
		register int c=x.b,d=x.a-x.b;
		d+=d<0?mod:0;
		int a_=(1ll*a*x.a+1ll*b*c)%mod;
		int b_=(1ll*a*x.b+1ll*b*d)%mod;
		return *this=Matrix(a_,b_);
	}
	inline Matrix operator ^ (ll n)
	{
		register Matrix ans(1,0),a=*this;
		while (n) {
			if (n&1) ans*=a;
			a*=a;
			n>>=1;
		}
		return ans;
	}
	inline Matrix& operator ^= (ll n)
	{
		Matrix c(1,0);
		while (n) {
			if (n&1) c*=*this;
			*this*=*this;
			n>>=1;
		}
		return *this=c;
	}
	inline bool operator != (const Matrix &x) const
	{
		return a!=x.a||b!=x.b;
	}
};
struct Segment_Tree{
	struct SegmentNode{
		Matrix mat,lazy;
		inline bool lazy_() {return lazy!=Matrix(1,0);} 
	}node[Maxm];
	
	inline void segment_init(int i,int l,int r)
	{
		(node+i)->lazy=Matrix(1,0);
		if (l==r) {
			(node+i)->mat^=a[l];
			return;
		}
		int mid=l+r>>1;
		segment_init(i<<1,l,mid);
		segment_init(i<<1|1,mid+1,r);
		register SegmentNode *ni=node+i,*nl=node+(i<<1),*nr=node+(i<<1|1);
		ni->mat=nl->mat+nr->mat;
	}
	
	inline void pushdown(int i)
	{
		register SegmentNode *ni=node+i,*nl=node+(i<<1),*nr=node+(i<<1|1);
		register Matrix x=ni->lazy;
		nl->lazy*=x;
		nl->mat*=x;
		nr->lazy*=x;
		nr->mat*=x;
		ni->lazy=Matrix(1,0);
	}
	
	inline void segment_modify(int i,int l,int r,int ql,int qr,Matrix v)
	{
		if (l<ql||r>qr) {
			int mid=l+r>>1;
			if ((node+i)->lazy_()) pushdown(i);
			if (mid>=ql) segment_modify(i<<1,l,mid,ql,qr,v);
			if (mid<qr) segment_modify(i<<1|1,mid+1,r,ql,qr,v);
			(node+i)->mat=(node+(i<<1))->mat+(node+(i<<1|1))->mat;
		}else {
			register SegmentNode *ni=node+i;
			ni->mat*=v;
			ni->lazy*=v;
		}
	}
	
	inline int segment_query(int i,int l,int r,int ql,int qr)
	{
		if (l<ql||r>qr) {
			int mid=l+r>>1,res=0;
			if ((node+i)->lazy_()) pushdown(i);
			if (mid>=ql) res=segment_query(i<<1,l,mid,ql,qr);
			if (mid<qr) res=md(res+segment_query(i<<1|1,mid+1,r,ql,qr));
			return res;
		}else {
			return (node+i)->mat.b;
		}
	}
}st;

int main()
{
	RI(n,m);
	for (int i=1;i<=n;++i) {
		RI(a[i]);
	}
	st.segment_init(1,1,n);
	for (int i=1;i<=m;++i) {
		int op,l,r,x;
		RI(op,l,r);
		if (op==1) {
			RI(x);
			st.segment_modify(1,1,n,l,r,Matrix()^x);
		}else {
			WI(st.segment_query(1,1,n,l,r));
			WC('\n');
		}
	}
	IO_flush();
	return 0;
}