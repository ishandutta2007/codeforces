#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

int N,K;
struct Fenwick
{
	ll v[100100];
	void Add(int i,ll x)
	{
		while(i<=N)v[i]+=x,i+=i&-i;
	}
	ll Ask(int i)
	{
		ll r=0;
		while(i)r+=v[i],i-=i&-i;
		return r;
	}
}T[11];

int main()
{
	scanf("%d%d",&N,&K);
	Fr(i,1,N)
	{
		int a;
		scanf("%d",&a);
		T[0].Add(a,1);
		Fr(k,1,K)T[k].Add(a,T[k-1].Ask(a-1));
	}
	printf("%lld\n",T[K].Ask(N));
	return 0;
}