#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <stdexcept>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=1e5+100,Z=1e9+100;


struct Seg{ll v;int z,L,R;}T[MX<<6];
#define li T[i].L
#define ri T[i].R
int cnt;
void Open(int& x){if(!x)x=++cnt;}
void update(int i,int x,int l,int r){T[i].v+=(ll)x*(r-l+1),T[i].z+=x;}
void pushup(int i){T[i].v=T[li].v+T[ri].v;}
void pushdown(int i,int l,int r)
{
	int m=(l+r)>>1;
	if(T[i].z)update(li,T[i].z,l,m),update(ri,T[i].z,m+1,r),T[i].z=0;
}
void Add(int i,int x,int a,int b,int l,int r)
{
	if(a<=l&&r<=b){update(i,x,l,r);return;}
	int m=(l+r)>>1;
	Open(li),Open(ri),pushdown(i,l,r);
	if(a<=m)Add(li,x,a,b,l,m);
	if(b>m)Add(ri,x,a,b,m+1,r);
	pushup(i);
}
double Bin(int i,ll x,int l,int r)
{
//	printf("%d %d %d %lld %lld\n",i,l,r,T[i].v,T[li].v);
	if(l==r)return (double)x/T[i].v;
	Open(li),Open(ri),pushdown(i,l,r);
	int m=(l+r)>>1;
	if(x<=T[li].v)return Bin(li,x,l,m);
	else return (m-l+1)+Bin(ri,x-T[li].v,m+1,r);
}


int N,M;
int H[MX];

int main()
{
	scanf("%d%d",&N,&M);
	int t=0,op,x;
	ll v;
	Open(t);
	Fr(i,1,N)
	{
		scanf("%d",H+i);
		Add(t,1,H[i]+1,Z,1,Z);
	}
	Fr(i,1,M)
	{
		scanf("%d",&op);
		switch(op)
		{
		case 1:
			scanf("%d%lld",&x,&v);
			Add(t,-1,H[x]+1,Z,1,Z);
			H[x]=v;
			Add(t,1,H[x]+1,Z,1,Z);
			break;
		case 2:
			scanf("%lld",&v);
		/*	if(v>T[t].v)
			{
				v-=T[t].v;
				printf("%f\n",(double)v/N+Z);
				break;
			}*/
			printf("%f\n",Bin(t,v,1,Z));
			break;
		}
	}
	return 0;
}