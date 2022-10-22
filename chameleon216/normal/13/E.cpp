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
using namespace std;
typedef long long ll;
const int MX=2e5+100;
int N,M;
int A[MX];
template<typename T>
void accio(T& x)
{
	char c,l;
	for(c=0;!isdigit(c);c=getchar())l=c;
	for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
	if(l=='-')x=-x;
}

struct LCT{int sz,z,s[2],f;}T[MX];
#define lx T[x].s[0]
#define ly T[y].s[0]
#define rx T[x].s[1]
#define fx T[x].f
void Rev(int x){swap(lx,rx),T[x].z^=1;}
void pushup(int x){T[x].sz=T[lx].sz+1+T[rx].sz;}
void pushdown(int x){if(T[x].z)Rev(lx),Rev(rx),T[x].z=0;}
bool isRoot(int x){return T[fx].s[0]!=x&&T[fx].s[1]!=x;}
int Get(int x){return T[fx].s[1]==x;}
void Rot(int x)
{
	int k=Get(x),y=T[x].f,z=T[x].s[k^1],w=T[y].f,j=Get(y);
	if(!isRoot(y))T[w].s[j]=x;
	T[x].s[k^1]=y,T[y].s[k]=z;
	T[x].f=w,T[y].f=x,T[z].f=y;
	pushup(y);
}
void PushTop(int x)
{
	if(!isRoot(x))PushTop(fx);
	pushdown(x);
}
void Splay(int x)
{
	PushTop(x);
	while(!isRoot(x))
	{
		int y=fx;
		if(isRoot(y))Rot(x);
		else if(Get(x)==Get(y))Rot(y),Rot(x);
		else Rot(x),Rot(x);
	}
	pushup(x);
}
void Access(int x)
{
	for(int y=0;x;y=x,x=fx)
		Splay(x),rx=y,pushup(x);
}
void Root(int x)
{
	Access(x),Splay(x),Rev(x);
}
void Split(int x,int y)
{
	Root(x),Access(y),Splay(y);
}
void Link(int x,int y)
{
	Root(x),fx=y;
}
void Cut(int x,int y)
{
	Split(x,y),fx=ly=0,pushup(y);
}


int main()
{
	accio(N),accio(M);
	int op,x,y;
	Fr(i,1,N+1)pushup(i);
	Fr(i,1,N)
	{
		accio(x);
		A[i]=min(i+x,N+1);
		Link(i,A[i]);
	}
	Fr(i,1,M)
	{
		accio(op),accio(x);
		if(op==1)
		{
			Split(N+1,x);
			Splay(N+1);
			int y=T[N+1].s[1];
			while(ly)pushdown(y),y=ly;
			printf("%d %d\n",y,T[N+1].sz-1);
			Splay(y);
		}
		else
		{
			accio(y);
			Cut(x,A[x]);
			A[x]=min(x+y,N+1);
			Link(x,A[x]);
		}
	}
	return 0;
}