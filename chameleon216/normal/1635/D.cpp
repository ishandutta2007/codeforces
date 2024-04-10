#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <set>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=200100,Mod=1000000007;
int N,P,F[MX],A[MX];

int Len(int x)
{
	int c=0;
	while(x)x>>=1,++c;
	return c;
}

int main()
{
	scanf("%d%d",&N,&P);
	F[1]=F[2]=1;
	Fr(i,3,P)F[i]=(F[i-1]+F[i-2])%Mod;
	Fr(i,2,P)F[i]=(F[i]+F[i-1])%Mod;
	Fr(i,1,N)scanf("%d",&A[i]);
	sort(A+1,A+N+1);
	set<int> se;
	int ans=0;
	Fr(i,1,N)
	{
		int b=1;
		for(int a=A[i];a;)
		{
			if(se.count(a)){b=0;break;}
			if(a&1)a>>=1;
			else if((a&3)==0)a>>=2;
			else break;
		}
		if(b)se.insert(A[i]),ans=(ans+F[P-Len(A[i])+1])%Mod;
	}
	printf("%d\n",ans);
	return 0;
}