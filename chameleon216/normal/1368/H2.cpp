#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
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
	int tp;
	
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	
	char g()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
	}
	void a(char& c)
	{
		do c=g();
		while(c<=32);
	}
	void y(char* s)
	{
		do *s=g();
		while(*s<=32);
		while(*s>32)*++s=g();
		*s=0;
	}
	template<typename T>
	void d(T& x)
	{
		char c=g(),l=0;
		for(x=0;!isdigit(c);c=g())l=c;
		for(;isdigit(c);c=g())x=x*10-'0'+c;
		if(l=='-')x=-x;
	}
	
	void w(char c)
	{
		if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
		*r++=c;
	}
	void z(const char* s)
	{
		while(*s)w(*s++);
	}
	template<typename T>
	void n(T x)
	{
		if(x<0)w('-'),x=-x;
		do stk[++tp]=x%10+'0';
		while(x/=10);
		while(tp)w(stk[tp--]);
	}
}IO;

const int MX=100100,Inf=0x3f3f3f3f;
int N,M,Q;
char U[MX],D[MX],L[MX],R[MX];

struct Matrix
{
	int x[2][2];
	Matrix(){}
	Matrix(int u,int d,int n)
	{
		Fr(i,0,1)Fr(j,0,1)
			x[i][j]=(i^j)*n+(j^u)+(j^d);
	}
};
inline Matrix operator*(const Matrix& a,const Matrix& b)
{
	Matrix c;
	c.x[0][0]=min(a.x[0][0]+b.x[0][0],a.x[0][1]+b.x[1][0]);
	c.x[0][1]=min(a.x[0][0]+b.x[0][1],a.x[0][1]+b.x[1][1]);
	c.x[1][0]=min(a.x[1][0]+b.x[0][0],a.x[1][1]+b.x[1][0]);
	c.x[1][1]=min(a.x[1][0]+b.x[0][1],a.x[1][1]+b.x[1][1]);
	return c;
}

#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
const int I=2,J=3;
struct Node
{
	Matrix f,g;
	int u,d,len;
	char y,z;
	void U_(){swap(f,g),u=len-u,y^=1;}
	void F_()
	{
		swap(f.x[1][1],f.x[0][0]);
		swap(f.x[1][0],f.x[0][1]);
		swap(g.x[1][1],g.x[0][0]);
		swap(g.x[1][0],g.x[0][1]);
		u=len-u,d=len-d,z^=1;
	}
}T[MX*8];
inline void PushUp(int i)
{
	T[i].f=T[li].f*T[ri].f;
	T[i].g=T[li].g*T[ri].g;
	T[i].u=T[li].u+T[ri].u;
	T[i].d=T[li].d+T[ri].d;
}
inline void PushDown(int i)
{
	if(T[i].y)T[li].U_(),T[ri].U_(),T[i].y=0;
	if(T[i].z)T[li].F_(),T[ri].F_(),T[i].z=0;
}
void Build(int i,int l,int r,char u[],char d[],int n)
{
	T[i].len=r-l+1;
	if(l==r)
	{
		T[i].u=u[l],T[i].d=d[l];
		T[i].f=Matrix(u[l],d[l],n);
		T[i].g=Matrix(u[l]^1,d[l],n);
		return;
	}
	Build(li,l,mid,u,d,n);
	Build(ri,mid+1,r,u,d,n);
	PushUp(i);
}
void Flip(int i,int l,int r,int a,int b,int p)
{
	if(a<=l&&r<=b)
	{
		T[i].U_();
		if(p)T[i].F_();
		return;
	}
	PushDown(i);
	if(a<=mid)Flip(li,l,mid,a,b,p);
	if(b>mid)Flip(ri,mid+1,r,a,b,p);
	PushUp(i);
}

int Query()
{
	int l=T[I].u,r=T[I].d,u=T[J].u,d=T[J].d;
	Matrix mx=T[I].f,my=T[J].f;
	return min(min(min(min(min(min(min(
		l+my.x[0][0]+r,
		N-l+my.x[1][0]+r),
		l+my.x[0][1]+N-r),
		N-l+my.x[1][1]+N-r),
		u+mx.x[0][0]+d),
		M-u+mx.x[1][0]+d),
		u+mx.x[0][1]+M-d),
		M-u+mx.x[1][1]+M-d);
}

int main()
{
	IO.d(N),IO.d(M),IO.d(Q),IO.y(L+1),IO.y(R+1),IO.y(U+1),IO.y(D+1);
	Fr(i,1,N)L[i]=L[i]=='B',R[i]=R[i]=='B';
	Fr(i,1,M)U[i]=U[i]=='B',D[i]=D[i]=='B';
	Build(I,1,N,L,R,M);
	Build(J,1,M,U,D,N);
	
	IO.n(Query()),IO.w('\n');
	Fr(i,1,Q)
	{
		char o;
		int l,r;
		IO.a(o),IO.d(l),IO.d(r);
		if(o=='L')Flip(I,1,N,l,r,0);
		else if(o=='R')Flip(I,1,N,l,r,1);
		else if(o=='U')Flip(J,1,M,l,r,0);
		else Flip(J,1,M,l,r,1);
		IO.n(Query()),IO.w('\n');
	}
	return 0;
}