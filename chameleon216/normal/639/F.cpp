#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
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
	FastIO(){p=q=ib,r=ob;}
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
	template<typename Tp>
	void rd(Tp& x)
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
	void ws(const char* s)
	{
		while(*s)w(*s++);
	}
}IO;

const int MX=300100,Inf=0x3f3f3f3f;
int N,M,Q;

struct LinkCutTree
{
	int c[2],f,h,a;
	char z;
}T[MX*3];
int tc;
inline void Rev(int x){if(x)swap(T[x].c[0],T[x].c[1]),T[x].z^=1;}
inline void Put(int x,int a){if(x)T[x].h+=a,T[x].a+=a;}
inline void PushDown(int x)
{
	int l=T[x].c[0],r=T[x].c[1];
	if(T[x].z)Rev(l),Rev(r),T[x].z=0;
	if(T[x].a)Put(l,T[x].a),Put(r,T[x].a),T[x].a=0;
}
inline void PushUp(int x){T[x].h=min(T[T[x].c[0]].h,T[T[x].c[1]].h);}
void Init()
{
	tc=N,T[0].h=Inf;
	Fr(x,1,tc)PushUp(x);
}

inline int Get(int x){return x==T[T[x].f].c[1];}
inline bool IsRoot(int x){return x!=T[T[x].f].c[Get(x)];}
void Rotate(int x)
{
	int y=T[x].f,w=T[y].f,a=Get(x),b=Get(y),z=T[x].c[a^1];
	if(!IsRoot(y))T[w].c[b]=x;
	T[x].c[a^1]=y,T[y].c[a]=z;
	T[x].f=w,T[y].f=x,T[z].f=y;
	PushUp(y);
}
void Splay(int x)
{
	while(!IsRoot(x))
	{
		int y=T[x].f;
		if(IsRoot(y))Rotate(x);
		else if(Get(x)==Get(y))Rotate(y),Rotate(x);
		else Rotate(x),Rotate(x);
	}
	PushUp(x);
}

void PushAll(int x){if(x)PushAll(T[x].f),PushDown(x);}
void Access(int x)
{
	PushAll(x);
	int y=0,z=x;
	while(x)
	{
		Splay(x),T[x].c[1]=y,PushUp(x);
		y=x,x=T[x].f;
	}
	Splay(z);
}
void Evert(int x){Access(x),Rev(x);}

bool Check(int x,int y)
{
	Evert(x),Access(y);
	return x==y||T[x].f;
}
void Link(int x,int y)
{
	T[x].f=y;
	PushDown(x),T[x].c[0]=++tc,T[tc].f=x,PushUp(x);
}
void Cut(int x,int y)
{
	T[x].c[1]=T[x].f=T[y].c[0]=0;
	PushUp(x),PushUp(y);
}

struct Edge{int x,y,o;}E[MX];
int V[MX],vc,ec,las;
int Calc(int x)
{
	x=(x+las)%N;
	if(!x)x=N;
	return x;
}

int main()
{
	IO.rd(N),IO.rd(M),IO.rd(Q);
	Init();
	Fr(i,1,M)
	{
		int x,y;
		IO.rd(x),IO.rd(y);
		if(Check(x,y))Put(y,1);
		else Link(x,y);
	}
	Fr(id,1,Q)
	{
		IO.rd(vc),IO.rd(ec);
		Fr(i,1,vc)IO.rd(V[i]),V[i]=Calc(V[i]);
		Fr(i,1,ec)IO.rd(E[i].x),IO.rd(E[i].y),E[i].x=Calc(E[i].x),E[i].y=Calc(E[i].y);
		Fr(i,1,ec)
		{
			int x=E[i].x,y=E[i].y;
			if(Check(x,y))E[i].o=1,Put(y,1);
			else E[i].o=0,Link(x,y);
		}
		int b=1;
		Fr(i,2,vc)
		{
			int x=V[1],y=V[i];
			if(!Check(x,y)||!T[y].h){b=0;break;}
		}
		IO.ws(b?"YES\n":"NO\n");
		Fl(i,ec,1)
		{
			int x=E[i].x,y=E[i].y;
			Check(x,y);
			if(E[i].o)Put(y,-1);
			else Cut(x,y);
		}
		if(b)las=(las+id)%N;
	}
	return 0;
}