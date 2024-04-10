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

int N,K;
struct Int
{
	int b[18];
	Int(int x)
	{
		Fr(i,0,17)b[i]=x%K,x/=K;
	}
	int Num()
	{
		int x=0;
		Fl(i,17,0)x=x*K+b[i];
		return x;
	}
};

Int operator~(Int x)
{
	Fr(i,0,17)x.b[i]=(K-x.b[i])%K;
	return x;
}

Int operator^(Int x,const Int& y)
{
	Fr(i,0,17)x.b[i]=(x.b[i]+y.b[i])%K;
	return x;
}


bool Query(int x)
{
	printf("%d\n",x),fflush(stdout);
	int y=0;
	scanf("%d",&y);
	return y;
}

//2333333333333
int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d%d",&N,&K);
		Int x=0;
		Fo(i,0,N)
		{
			Int y=i^x;
			if(i&1)y=~y;
			if(Query(y.Num()))break;
			x=x^(i&1?y:~y);
		}
	}
	return 0;
}