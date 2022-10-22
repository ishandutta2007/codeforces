#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x],y=E[i].y;i;\
						i=E[i].nx,y=E[i].y)
using namespace std;
typedef long long ll;
const int MX=1e5+100;
struct Accio{
	template<typename T>
	Accio& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;return *this;
	}
}accio;
struct Star{int y,nx;}E[MX<<1];
int H[MX],ec;
void add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int N,M,R;
int X[MX];

int D[MX];
void dfs1(int x,int f,int d){D[x]=d;Fe(i,x)if(y!=f)dfs1(y,x,d+1);}

struct Seg
{
	int v,L,R;
	void pushup();
	void ins(int i,int x,int l=1,int r=N);
	int ask(int a,int b,int l=1,int r=N);
}T[MX<<6]; int cnt;
int Copy(int i){return T[++cnt]=T[i],cnt;}
void Seg::pushup(){v=min(T[L].v,T[R].v);}
void Seg::ins(int i,int x,int l,int r)
{
	if(l==r){v=x;return;}
	int m=(l+r)>>1;
	if(i<=m)L=Copy(L),T[L].ins(i,x,l,m);
	else R=Copy(R),T[R].ins(i,x,m+1,r);
	pushup();
}
int Seg::ask(int a,int b,int l,int r)
{
	if(a<=l&&r<=b)return v;
	int m=(l+r)>>1,A=INT_MAX;
	if(a<=m&&L)A=min(A,T[L].ask(a,b,l,m));
	if(b>m&&R)A=min(A,T[R].ask(a,b,m+1,r));
	return A;
}

int Merge(int a,int b,int l=1,int r=N)
{
	if(!a||!b)return a+b;
	int t=Copy(0);
	if(l==r)
	{
		T[t].v=min(T[a].v,T[b].v);
		return t;
	}
	int m=(l+r)>>1;
	T[t].L=Merge(T[a].L,T[b].L,l,m);
	T[t].R=Merge(T[a].R,T[b].R,m+1,r);
	T[t].pushup();
	return t;
}

int t[MX];

void dfs2(int x,int f)
{
	Fe(i,x)if(y!=f)
	{
		dfs2(y,x);
		t[x]=Merge(t[x],t[y]);
	}
}

int main()
{
	T[0].v=INT_MAX;
	
	accio>>N>>R;
	Fr(i,1,N)accio>>X[i];
	int x,y,k;
	Fr(i,2,N)accio>>x>>y,add(x,y),add(y,x);
	dfs1(R,0,1);
	Fr(i,1,N)t[i]=Copy(0),T[t[i]].ins(D[i],X[i]);
	accio>>M;
	
	dfs2(R,0);
//	Fr(i,1,N)Fr(j,1,N)printf("[%d,%d] %d\n",i,j,T[t[2]].ask(i,j));
	
	int lans=0;
	Fr(i,1,M)
	{
		accio>>x>>k;
		x=(x+lans)%N+1;
		k=(k+lans)%N;
//		printf("%d %d\n",x,k);
//		printf("%d %d\n",D[x],D[x]+k);
		lans=T[t[x]].ask(D[x],D[x]+k);
		printf("%d\n",lans);
	}
	return 0;
}