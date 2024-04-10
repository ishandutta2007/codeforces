#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <utility>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=6000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int N,K,M;
ll A[MX],D[MX];

struct MonoQueue
{
	int qi[MX],cnt,l,r,w;
	ll qx[MX];
	void init(int v){cnt=0,l=1,r=0,w=v;}
	void push(ll x)
	{
		while(l<=r&&x>=qx[r])--r;
		qi[++r]=++cnt,qx[r]=x;
		if(cnt-qi[l]>=w)++l;
	}
	ll front(){return l<=r?qx[l]:-Inf;}
}Q;



int main()
{
	scanf("%d%d%d",&N,&K,&M);
	Fr(i,1,N)scanf("%lld",A+i);
	memset(D,0xc0,sizeof(D));
	Fr(j,1,M)
	{
		Q.init(K);
		if(j==1)Q.push(0);
		Fr(i,1,N)
		{
			ll t=Q.front();
			Q.push(D[i]),D[i]=t+A[i];
		}
//		Fr(i,1,N)printf("%lld ",D[i]);putchar('\n');
	}
	ll ans=-Inf;
	Fr(i,N-K+1,N)ans=max(ans,D[i]);
	if(ans>-Inf/2)printf("%lld\n",ans);
	else printf("-1\n");
	return 0;
}