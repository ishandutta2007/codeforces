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
const int MX=330000,MY=1000100,W=1000000;

int N,M;
int A[MX];


char isp[MY];
int P[MY],pc;
int F[MY],J[MY];
void Euler()
{
	memset(isp,1,sizeof(isp));
	isp[0]=isp[1]=0,F[1]=1;
	Fr(i,2,W)
	{
		if(isp[i])P[++pc]=i,J[i]=1,F[i]=2;
		Fr(j,1,pc)
		{
			int p=P[j];
			if(i*p>W)break;
			isp[i*p]=0;
			if(i%p)J[i*p]=i,F[i*p]=F[i]*2;
			else {J[i*p]=J[i],F[i*p]=F[i]+F[J[i]];break;}
		}
	}
}


struct Seg{ll v;int t,l,r;}T[MX<<2];
int cnt;
#define li (i<<1)
#define ri (i<<1|1)
void pushup(int i)
{
	T[i].v=T[li].v+T[ri].v;
	T[i].t=T[li].t&T[ri].t;
}
void Build(int i,int l,int r)
{
	T[i].l=l,T[i].r=r;
	if(l==r){T[i].v=A[l],T[i].t=T[i].v<=2;return;}
	int m=(l+r)>>1;
	Build(li,l,m),Build(ri,m+1,r);
	pushup(i);
}
void Modify(int i,int a,int b)
{
	if(T[i].t)return;
	if(T[i].l==T[i].r)
		{T[i].v=F[T[i].v],T[i].t=T[i].v<=2;return;}
	if(a<=T[li].r)Modify(li,a,b);
	if(b>=T[ri].l)Modify(ri,a,b);
	pushup(i);
}
ll Ask(int i,int a,int b)
{
	if(a<=T[i].l&&T[i].r<=b)return T[i].v;
	ll res=0;
	if(a<=T[li].r)res+=Ask(li,a,b);
	if(b>=T[ri].l)res+=Ask(ri,a,b);
	return res;
}



int main()
{
	Euler();
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%d",A+i);
	Build(1,1,N);
	Fr(i,1,M)
	{
		int o,l,r;
		scanf("%d%d%d",&o,&l,&r);
		if(o==1)Modify(1,l,r);
		else if(o==2)printf("%lld\n",Ask(1,l,r));
	}
	return 0;
}