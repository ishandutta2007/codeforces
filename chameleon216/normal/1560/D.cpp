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

const int MX=120,Inf=0x3f3f3f3f;
int D[MX],dc,E[63][MX],ec[63];

struct Subseq
{
	int c[MX][10];
	void Build()
	{
		memset(c[dc+1],0,sizeof(c[dc+1]));
		Fl(i,dc,1)
		{
			memcpy(c[i],c[i+1],sizeof(c[i]));
			c[i][D[i]]=i+1;
		}
	}
	int Match(int k)
	{
		int x=1;
		Fr(i,1,ec[k])
		{
			x=c[x][E[k][i]];
			if(!x)return i-1;
		}
		return ec[k];
	}
}seq;

void Init()
{
	Fr(i,0,62)
	{
		ll y=1ll<<i;
		for(ll a=y;a;a/=10)E[i][++ec[i]]=a%10;
		reverse(E[i]+1,E[i]+ec[i]+1);
	}
}

int Calc(int x)
{
	int ans=Inf;
	dc=0;
	for(int a=x;a;a/=10)D[++dc]=a%10;
	reverse(D+1,D+dc+1);
	seq.Build();
	Fr(k,0,62)
	{
		int r=seq.Match(k);
		ans=min(ans,dc-r+ec[k]-r);
	}
	return ans;
}


int main()
{
	int t;
	scanf("%d",&t);
	Init();
	while(t --> 0)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",Calc(x));
	}
	return 0;
}