#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	
	FastIO(){p=q=ib,r=ob;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	
	char gc()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	void rc(char& c)
	{
		do c=gc();
		while(!isgraph(c));
	}
	void rs(char* s)
	{
		do *s=gc();
		while(!isgraph(*s));
		while(isgraph(*s))*++s=gc();
		*s=0;
	}
	template<typename T>
	void rd(T& x)
	{
		char c=gc(),l;
		for(l=0;!isdigit(c);c=gc())l=c;
		for(x=0;isdigit(c);c=gc())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void wc(char c)
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	void ws(const char* s)
	{
		while(*s)wc(*s++);
	}
	template<typename T>
	void wd(T x)
	{
		if(x<0)wc('-'),x=-x;
		int tp=0;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)wc(stk[tp--]);
	}
}IO;

const int MX=200100,Blo=3000;
int N,M,U[MX],uc,X[MX];

struct Change{int a,x;}C[MX];
struct Query{int l,r,t,id;}Q[MX];
int blo[MX],Aq[MX],cc,qc;
bool operator<(const Query& a,const Query& b)
{
	if(blo[a.l]!=blo[b.l])return a.l<b.l;
	if(blo[a.r]!=blo[b.r])return a.r<b.r;
	return (blo[a.r]&1)?a.t<b.t:a.t>b.t;
}

int cnt[MX],B[MX];
inline void Modify(int i,int w)
{
	int x=X[i];
	--B[cnt[x]],cnt[x]+=w,++B[cnt[x]];
}
inline void Update(int i,int l,int r)
{
	if(l<=C[i].a&&C[i].a<=r)Modify(C[i].a,-1);
	swap(X[C[i].a],C[i].x);
	if(l<=C[i].a&&C[i].a<=r)Modify(C[i].a,1);
}
int Mex()
{
	for(int i=1;;++i)if(!B[i])return i;
}

void MoQueue()
{
	Fr(i,1,N)blo[i]=(i-1)/Blo+1;
	sort(Q+1,Q+qc+1);
	int l=1,r=0,t=0;
	Fr(i,1,qc)
	{
		while(Q[i].l<l)Modify(--l,1);
		while(Q[i].r>r)Modify(++r,1);
		while(Q[i].l>l)Modify(l++,-1);
		while(Q[i].r<r)Modify(r--,-1);
		while(Q[i].t<t)Update(t--,l,r);
		while(Q[i].t>t)Update(++t,l,r);
		Aq[Q[i].id]=Mex();
	}
}


int main()
{
	IO.rd(N),IO.rd(M);
	Fr(i,1,N)IO.rd(X[i]),U[++uc]=X[i];
	Fr(i,1,M)
	{
		int o;
		IO.rd(o);
		if(o==1)
		{
			Query &q=Q[++qc];
			IO.rd(q.l),IO.rd(q.r),q.t=cc,q.id=qc;
		}
		else
		{
			Change &c=C[++cc];
			IO.rd(c.a),IO.rd(c.x),U[++uc]=c.x;
		}
	}
	
	sort(U+1,U+uc+1);
	uc=unique(U+1,U+uc+1)-U-1;
	Fr(i,1,N)X[i]=lower_bound(U+1,U+uc+1,X[i])-U;
	Fr(i,1,cc)C[i].x=lower_bound(U+1,U+uc+1,C[i].x)-U;
	
	MoQueue();
	Fr(i,1,qc)IO.wd(Aq[i]),IO.wc('\n');
	return 0;
}