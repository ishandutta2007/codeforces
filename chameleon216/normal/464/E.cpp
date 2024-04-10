#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <queue>
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
		int t=0;
		do stk[++t]=x%10+'0';
		while(x/=10);
		while(t)Put(stk[t--]);
	}
}IO;

const int MX=100100,W=100080,Mod=1000000007;
int N,M,Ns,Nt,P[MX];

struct Edge{int y,w,nx;}E[MX*2];
int H[MX],ec=1;
void Link(int x,int y,int w){E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;}

struct SegmentTree{int v,l,r;}T[MX*40];
int tc;
int Copy(int i){T[++tc]=T[i];return tc;}
int Comp(int x,int y,int l,int r)
{
	if(l==r)return T[x].v-T[y].v;
	int m=(l+r)>>1;
	if(T[T[x].r].v!=T[T[y].r].v)
		return Comp(T[x].r,T[y].r,m+1,r);
	else return Comp(T[x].l,T[y].l,l,m);
}
void Add(int& i,int l,int r,int a,int& f)
{
	if(f)return;
	if(a<=l)
	{
		if(T[i].v==P[r-l+1]-1){i=0;return;}
		if(l==r){i=Copy(i),T[i].v=1,f=1;return;}
	}
	i=Copy(i);
	int m=(l+r)>>1;
	if(a<=m)Add(T[i].l,l,m,a,f);
	Add(T[i].r,m+1,r,a,f);
	T[i].v=(T[T[i].l].v+(ll)P[m-l+1]*T[T[i].r].v)%Mod;
}

struct Node
{
	int x,d;
	Node(){}
	Node(int x_,int d_){x=x_,d=d_;}
};
bool operator<(const Node& a,const Node& b){return Comp(a.d,b.d,0,W)>0;}
int B[MX],D[MX],F[MX],Inf;
void Dijkstra()
{
	priority_queue<Node> q;
	Fr(i,1,N)D[i]=Inf;
	q.push(Node(Ns,0)),D[Ns]=0;
	while(!q.empty())
	{
		int x=q.top().x;
		q.pop();
		if(B[x])continue;
		B[x]=1;
		Fe(i,x,y)if(!B[y])
		{
			int d=D[x],b=0;
			Add(d,0,W,E[i].w,b);
			if(Comp(D[y],d,0,W)>0)
				D[y]=d,F[y]=x,q.push(Node(y,D[y]));
		}
	}
}

int res[MX],rc;

int main()
{
	IO.Read(N),IO.Read(M);
	Fr(i,1,M)
	{
		int x,y,w;
		IO.Read(x),IO.Read(y),IO.Read(w);
		Link(x,y,w),Link(y,x,w);
	}
	IO.Read(Ns),IO.Read(Nt);
	
	P[0]=1;
	Fr(i,1,W)P[i]=P[i-1]*2%Mod;
	
	int b=0;
	Add(Inf,0,W,W-2,b);
	Dijkstra();
	
	if(D[Nt]==Inf)IO.Write(-1),IO.Put('\n');
	else
	{
		for(int x=Nt;x;x=F[x])res[++rc]=x;
		IO.Write(T[D[Nt]].v),IO.Put('\n');
		IO.Write(rc),IO.Put('\n');
		while(rc)IO.Write(res[rc--]),IO.Put(' ');
		IO.Put('\n');
	}
	return 0;
}