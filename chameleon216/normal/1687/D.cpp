#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=2000100,N=2000000;
int M,A[MX],nx[MX];
ll L[MX],R[MX];

ll Match()
{
	ll k=0;
	int p=1;
	while(1)
	{
		while(k>=R[p])++p;
		int b=1;
		for(int i=p;L[i]-k<=N;++i)
		{
			int q=nx[max(L[i]-k,1ll)];
			if(q<=R[i]-k){k=R[i]+1-q,b=0;break;}
		}
		if(b)return k;
	}
}

int main()
{
	scanf("%d",&M);
	Fr(i,1,M)
	{
		int x;
		scanf("%d",&x);
		A[x]=1;
	}
	nx[N+1]=0x3f3f3f3f;
	Fl(i,N,1)nx[i]=A[i]?i:nx[i+1];
	Fr(i,1,N+2)
	{
		R[i]=(ll)(i+1)*(i+1);
		L[i]=(R[i]+(ll)i*i)/2+1;
		--R[i];
//		printf("%lld %lld\n",L[i],R[i]);
	}
	printf("%lld\n",Match());
	return 0;
}