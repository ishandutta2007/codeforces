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

const int MX=1000100;
int N,W,A[MX],S[MX];

int Work()
{
	scanf("%d%d",&N,&W);
	Fr(i,1,N)
	{
		int a;
		scanf("%d",&a);
		A[a]=1;
	}
	Fr(i,1,W)S[i]=S[i-1]+A[i];
	Fr(a,1,W)if(A[a])
	{
		for(int b=1;a*b<=W;++b)if(!A[b])
		{
			int l=a*b,r=min(a*(b+1)-1,W);
			if(S[r]-S[l-1])return 0;
		}
	}
	return 1;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		printf(Work()?"Yes\n":"No\n");
		Fr(i,0,W)A[i]=S[i]=0;
	}
	return 0;
}