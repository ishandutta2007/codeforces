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
const int MX=350000;
int N,M;
ll A[MX],B[MX];
inline int Sign(ll x){return x<0?-1:x>0;}
inline bool Check(int a,int b){return a&&b&&(a>0||b<0);}

struct Segment
{
	int ls,rs,ms,u,v;
	int l,r;
	void init(){u=v=B[l],ls=rs=ms=!!B[l];}
}T[MX<<2];
int P[MX];
#define li (i<<1)
#define ri (i<<1|1)
inline void PushUp(int i)
{
	Segment &t=T[i],&x=T[li],&y=T[ri];
	t.u=x.u,t.v=y.v;
	t.ls=x.ls,t.rs=y.rs,t.ms=max(x.ms,y.ms);
	if(Check(x.v,y.u))
	{
		if(x.ls==x.r-x.l+1)t.ls=x.ls+y.ls;
		if(y.rs==y.r-y.l+1)t.rs=x.rs+y.rs;
		t.ms=max(t.ms,x.rs+y.ls);
	}
}
void Build(int i,int l,int r)
{
	T[i].l=l,T[i].r=r;
	if(l==r){P[l]=i,T[i].init();return;}
	int m=(l+r)>>1;
	Build(li,l,m),Build(ri,m+1,r);
	PushUp(i);
}
void Modify(int a)
{
	int i=P[a];
	T[i].init(),i>>=1;
	while(i)PushUp(i),i>>=1;
}


int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",&A[i]);
	Fo(i,1,N)B[i]=A[i+1]-A[i];
	if(N>1)Build(1,1,N-1);
	scanf("%d",&M);
	Fr(i,1,M)
	{
		int l,r;
		ll x;
		scanf("%d%d%lld",&l,&r,&x),--l;
		if(N==1){printf("1\n");continue;}
		ll tl=B[l],tr=B[r];
		B[l]+=x,B[r]-=x;
		if(l>0&&Sign(tl)!=Sign(B[l]))Modify(l);
		if(r<N&&Sign(tr)!=Sign(B[r]))Modify(r);
		printf("%d\n",T[1].ms+1);
	}
	return 0;
}