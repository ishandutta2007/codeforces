#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MB=1<<20;
struct FastIO
{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	
	char Get()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	template<typename T>
	void Read(T& x)
	{
		char c=Get(),l=0;
		for(x=0;!isdigit(c);c=Get())l=c;
		for(;isdigit(c);c=Get())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void Put(char c)
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	template<typename T>
	void Write(T x)
	{
		if(x<0)Put('-'),x=-x;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)Put(stk[tp--]);
	}
}IO;

const int MX=100100,W=100000;
const ll InfL=0x3f3f3f3f3f3f3f3fll;
int N,A[MX],B[MX];

struct Edge{int y,nx;}E[MX*2];
int H[MX],ec;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

struct Line
{
	int k;
	ll b;
	Line(){}
	Line(int k_,ll b_){k=k_,b=b_;}
	ll Get(ll x){return k*x+b;}
};

struct LiChaoTree
{
	Line v;
	int l,r;
}T[MX];
int stk[MX],tc,tp;
inline int New(Line f)
{
	int i=tp?stk[tp--]:++tc;
	T[i].v=f,T[i].l=T[i].r=0;
	return i;
}
inline void Free(int i){stk[++tp]=i;}
void Ins(int& i,int l,int r,Line f)
{
	if(!i){i=New(f);return;}
	int m=(l+r)>>1;
	if(f.Get(m)<T[i].v.Get(m))swap(T[i].v,f);
	if(l==r)return;
	if(f.Get(l)<T[i].v.Get(l))Ins(T[i].l,l,m,f);
	if(f.Get(r)<T[i].v.Get(r))Ins(T[i].r,m+1,r,f);
}
ll Query(int i,int l,int r,int a)
{
	if(!i)return InfL;
	if(l==r)return T[i].v.Get(a);
	int m=(l+r)>>1;
	if(a<=m)return min(T[i].v.Get(a),Query(T[i].l,l,m,a));
	else return min(T[i].v.Get(a),Query(T[i].r,m+1,r,a));
}
void Merge(int& x,int y,int l,int r)
{
	if(!x||!y){x|=y;return;}
	int m=(l+r)>>1;
	Merge(T[x].l,T[y].l,l,m);
	Merge(T[x].r,T[y].r,m+1,r);
	Ins(x,l,r,T[y].v),Free(y);
}

int I[MX];
ll dp[MX];
void dfs1(int x,int f)
{
	int c=0;
	Fe(i,x,y)if(y!=f)
		++c,dfs1(y,x),Merge(I[x],I[y],-W,W);
	dp[x]=c?Query(I[x],-W,W,A[x]):0;
	Ins(I[x],-W,W,Line(B[x],dp[x]));
}

int main()
{
	IO.Read(N);
	Fr(i,1,N)IO.Read(A[i]);
	Fr(i,1,N)IO.Read(B[i]);
	Fr(i,2,N)
	{
		int x,y;
		IO.Read(x),IO.Read(y);
		Link(x,y),Link(y,x);
	}
	dfs1(1,0);
	Fr(x,1,N)IO.Write(dp[x]),IO.Put(' ');
	IO.Put('\n');
	return 0;
}