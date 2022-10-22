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
	
	char g()
	{
		if(p==q)
		{
			p=ib,q=ib+fread(ib,1,MB,stdin);
			if(p==q)return 0;
		}
		return *p++;
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
	void y(const char* s)
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

const int MX=400100;
int N,M,S,T,Ds,Dt;

struct Edge{int y,nx,b;}E[MX<<1];
int H[MX],ec=1;
void Link(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}
int Seek(int x,int y)
{
	Fe(i,x,z)if(y==z)return i;
	return 0;
}

int F[MX];
int Find(int x){return x==F[x]?x:F[x]=Find(F[x]);}

int B[MX],bc,Q[MX],cnt[4];
void dfs1(int x)
{
	B[x]=bc;
	Fe(i,x,y)
	{
		if(y==S)Q[bc]|=1;
		else if(y==T)Q[bc]|=2;
		else if(!B[y])dfs1(y),E[i].b=1,F[Find(y)]=Find(x);
	}
}

int main()
{
	IO.d(N),IO.d(M);
	Fr(i,1,M)
	{
		int x,y;
		IO.d(x),IO.d(y);
		Link(x,y),Link(y,x);
	}
	IO.d(S),IO.d(T),IO.d(Ds),IO.d(Dt);
	Fr(x,1,N)F[x]=x;
	Fr(x,1,N)if(x!=S&&x!=T&&!B[x])++bc,dfs1(x);
	
	Fr(i,1,bc)++cnt[Q[i]];
	Fe(i,S,y)if(Q[B[y]]==1)
	{
		int fy=Find(y),fs=Find(S);
		if(fs!=fy)F[fs]=fy,E[i].b=1,--Ds;
	}
	Fe(i,T,y)if(Q[B[y]]==2)
	{
		int fy=Find(y),ft=Find(T);
		if(ft!=fy)F[ft]=fy,E[i].b=1,--Dt;
	}
	if(Ds<=0||Dt<=0||Ds+Dt<=cnt[3]){IO.y("No\n");return 0;}
	if(!cnt[3])E[Seek(S,T)].b=1,--Ds,--Dt;
	else
	{
		Fe(i,S,y)if(Q[B[y]]==3&&Ds)
		{
			int fy=Find(y),fs=Find(S);
			if(fs!=fy)F[fs]=fy,E[i].b=1,--Ds;
		}
		Fe(i,T,y)if(Q[B[y]]==3&&Dt)
		{
			int fy=Find(y),ft=Find(T);
			if(ft!=fy)F[ft]=fy,E[i].b=1,--Dt;
		}
	}
	IO.y("Yes\n");
	Fr(i,2,ec)if(E[i].b)
	{
		IO.n(E[i].y),IO.w(' ');
		IO.n(E[i^1].y),IO.w('\n');
	}
	return 0;
}