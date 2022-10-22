#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=120000;
int N,K,M;
int A[MX];

struct SegTree
{
	int v,z,sz,L,R;
	void assign(int x){v=x,z=x;}
}T[MX<<7];
int cnt,segt,segb;
#define li T[i].L
#define ri T[i].R
inline int New(){return ++cnt;}
inline int Copy(int i){T[++cnt]=T[i];return cnt;}
inline void pushup(int i){T[i].v=min(T[li].v,T[ri].v);}
inline void pushdown(int i)
{
	li=Copy(li),ri=Copy(ri);
	int &z=T[i].z;
	if(z)T[li].assign(z),T[ri].assign(z),z=0;
}
void Build(int i,int l,int r)
{
	if(l==r){T[i].v=A[l],T[i].sz=1;return;}
	int m=(l+r)>>1;
	li=New(),Build(li,l,m);
	ri=New(),Build(ri,m+1,r);
	T[i].sz=T[li].sz+T[ri].sz;
	pushup(i);
}
void Cuild(int i,int l,int r,int t)
{
	if(l==r){T[i]=T[t];return;}
	int m=(l+r)>>1;
	li=New(),Cuild(li,l,m,t);
	ri=New(),Cuild(ri,m+1,r,t);
	T[i].sz=T[li].sz+T[ri].sz;
	pushup(i);
}
void Assign(int i,int l,int r,int a,int b,int x)
{
	if(a<=l&&r<=b){T[i].assign(x);return;}
	pushdown(i);
	int m=l+T[li].sz-1;
	if(a<=m)Assign(li,l,m,a,b,x);
	if(b>m)Assign(ri,m+1,r,a,b,x);
	pushup(i);
}
int Ask(int i,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)return T[i].v;
	pushdown(i);
	int m=l+T[li].sz-1;
	if(b<=m)return Ask(li,l,m,a,b);
	if(a>m)return Ask(ri,m+1,r,a,b);
	return min(Ask(li,l,m,a,b),Ask(ri,m+1,r,a,b));
}



int main()
{
	scanf("%d%d",&N,&K);
	Fr(i,1,N)scanf("%d",A+i);
	segb=New(),segt=New();
	Build(segb,1,N);
	Cuild(segt,1,K,segb);
	scanf("%d",&M);
	int o,l,r,x;
	Fr(i,1,M)
	{
		scanf("%d%d%d",&o,&l,&r);
		switch(o)
		{
		case 1:scanf("%d",&x),Assign(segt,1,N*K,l,r,x);break;
		case 2:printf("%d\n",Ask(segt,1,N*K,l,r));break;
		}
	}
	return 0;
}