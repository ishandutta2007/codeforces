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

const int MX=200100;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll Abs(ll a){return a>=0?a:-a;}

int N;
ll A[MX],C[MX];

ll val[MX<<2];
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
void Build(int i,int l,int r)
{
	if(l==r){val[i]=C[l];return;}
	Build(li,l,mid),Build(ri,mid+1,r);
	val[i]=gcd(val[li],val[ri]);
}
void Bin(int i,int l,int r,int a,int& f,int& b,ll& g)
{
	if(f)return;
	if(a<=l)
	{
		ll h=gcd(g,val[i]);
		if(h!=1){b=r,g=h;return;}
		if(l==r){f=1;return;}
	}
	if(a<=mid)Bin(li,l,mid,a,f,b,g);
	Bin(ri,mid+1,r,a,f,b,g);
}


int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",&A[i]);
	if(N==1){puts("1");return 0;}
	Fr(i,1,N-1)C[i]=Abs(A[i+1]-A[i]);
//	Fr(i,1,N-1)printf("%lld ",C[i]);putchar('\n');
	Build(1,1,N-1);
	int ans=1;
	Fr(l,1,N-1)
	{
		int f=0,r=l-1;
		ll g=0;
		Bin(1,1,N-1,l,f,r,g);
		ans=max(ans,r-l+2);
	}
	printf("%d\n",ans);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		mian();
	}
	return 0;
}