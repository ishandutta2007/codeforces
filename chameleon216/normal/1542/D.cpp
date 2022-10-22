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
const int MX=600,Mod=998244353;

int N;
struct Pt{char o;int x;}P[MX];
ll D[MX],E[MX];
ll Calc(int k)
{
	ll *d=D,*e=E;
	memset(d,0,sizeof(D));
	d[0]=1;
	Fr(i,1,N)
	{
		memset(e,0,sizeof(D));
		
		if(i==k)
			Fr(j,0,N)e[j]+=d[j];
		else if(P[i].o=='-'&&i<k)
			Fr(j,0,N)e[j]+=d[j],e[max(j-1,0)]+=d[j];
		else if(P[i].o=='-'&&i>k)
			Fr(j,0,N)
			{
				e[j]+=d[j];
				if(j)e[j-1]+=d[j];
			}
		else if(P[i].x<P[k].x||(P[i].x==P[k].x&&i<k))
			Fr(j,0,N)e[j]+=d[j],e[j+1]+=d[j];
		else
			Fr(j,0,N)e[j]+=2*d[j];
		Fr(j,0,N)e[j]%=Mod;
		
		swap(d,e);
	}
	ll sum=0;
	Fr(j,0,N)sum+=d[j],sum%=Mod;
	return sum;
}

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)
	{
		scanf(" %c",&P[i].o);
		if(P[i].o=='+')scanf("%d",&P[i].x);
	}
	ll sum=0;
	Fr(i,1,N)if(P[i].o=='+')
		sum+=P[i].x*Calc(i)%Mod,sum%=Mod;
	printf("%lld\n",sum);
	return 0;
}