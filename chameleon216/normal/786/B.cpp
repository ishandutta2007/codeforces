#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <queue>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=330000; //
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int N,M,S;
template<typename T>
void Accio(T& x)
{
	char c,l;
	for(c=0;!isdigit(c);c=getchar())l=c;
	for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
	if(l=='-')x=-x;
}

struct Edge{int y,nx;ll w;}E[MX<<4]; //log(N)
int H[MX],ec;
void Add(int x,int y,ll w)
{
	E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;
}

int nc; //
int Node(){return ++nc;} //
int P[MX]; // ()

struct Seg{int in,out,L,R;}T[MX]; //inout
int sc=1;
int New(){return ++sc;}
#define li T[i].L
#define ri T[i].R
void Build(int i,int l,int r)
{
	if(l==r){P[l]=T[i].in=T[i].out=Node();return;}
	T[i].in=Node(),T[i].out=Node();
	int m=(l+r)>>1;
	li=New(),Build(li,l,m);
	ri=New(),Build(ri,m+1,r);
	Add(T[i].in,T[li].in,0),Add(T[i].in,T[ri].in,0);
	Add(T[li].out,T[i].out,0),Add(T[ri].out,T[i].out,0);
}
void Add1(int i,int l,int r,int x,int a,int b,ll w) //xa~b
{
	if(a<=l&&r<=b){Add(P[x],T[i].in,w);return;}
	int m=(l+r)>>1;
	if(a<=m)Add1(li,l,m,x,a,b,w);
	if(b>m)Add1(ri,m+1,r,x,a,b,w);
}
void Add2(int i,int l,int r,int a,int b,int y,ll w) //a~by
{
	if(a<=l&&r<=b){Add(T[i].out,P[y],w);return;}
	int m=(l+r)>>1;
	if(a<=m)Add2(li,l,m,a,b,y,w);
	if(b>m)Add2(ri,m+1,r,a,b,y,w);
}

#define y E[i].y
#define w E[i].w
struct Pt
{
	int x;ll d; Pt(){}
	Pt(int x_,ll d_):x(x_),d(d_){}
};
bool operator<(const Pt& a,const Pt& b){return a.d>b.d;}

bool B[MX];
ll D[MX];
priority_queue<Pt> Q;
void Dijkstra(int s)
{
	Fill(D,0x3f);
	D[s]=0,Q.push(Pt(s,0));
	while(!Q.empty())
	{
		int x=Q.top().x;
		Q.pop();
		if(B[x])continue;
		B[x]=1;
		Fe(i,x)if(D[y]>D[x]+w)
			D[y]=D[x]+w,Q.push(Pt(y,D[y]));
	}
}
#undef y
#undef w

int main()
{
	Accio(N),Accio(M),Accio(S);
	Build(1,1,N);
	int op,x,y,l,r;ll w;
	Fr(i,1,M)
	{
		Accio(op);
		switch(op)
		{
			case 1:
				Accio(x),Accio(y),Accio(w);
				Add(P[x],P[y],w);break;
			case 2:
				Accio(x),Accio(l),Accio(r),Accio(w);
				Add1(1,1,N,x,l,r,w);break;
			case 3:
				Accio(y),Accio(l),Accio(r),Accio(w);
				Add2(1,1,N,l,r,y,w);break;
		}
	}
	//printf("%d %d %d\n",sc,nc,ec);
	Dijkstra(P[S]);
	Fr(i,1,N)
	{
		if(D[P[i]]==Inf)printf("-1 ");
		else printf("%lld ",D[P[i]]);
	}
	//Fr(i,1,nc)printf("%lld ",D[i]);
	putchar('\n');
	return 0;
}