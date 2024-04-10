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
using namespace std;
typedef long long ll;
const int MX=160000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int N,M;
ll E,A[MX],B[MX],T[MX];
ll Abs(ll x){return x>=0?x:-x;}
ll D[MX];

struct MonotonousQueue
{
	ll qi[MX],qx[MX];
	int l,r;
	void init(){l=1,r=0;}
	void push(ll i,ll x)
	{
		while(l<=r&&x>=qx[r])--r;
		qi[++r]=i,qx[r]=x;
	}
	void pop(ll i)
	{
		while(l<=r&&qi[l]<=i)++l;
	}
	ll ask(){return qx[l];}
}Q;


int main()
{
	scanf("%d%d%lld",&N,&M,&E);
	Fr(i,1,M)scanf("%lld%lld%lld",A+i,B+i,T+i);
	T[0]=-N;
	Fr(i,1,M)
	{
		ll d=E*(T[i]-T[i-1]),r=0;
		Q.init();
		Fr(j,1,N)
		{
			while(r<j+d&&r<N)++r,Q.push(r,D[r]);
			Q.pop(j-d-1);
			D[j]=Q.ask()+B[i]-Abs(A[i]-j);
		}
	}
	ll ans=-Inf;
	Fr(i,1,N)ans=max(ans,D[i]);
	printf("%lld\n",ans);
	return 0;
}