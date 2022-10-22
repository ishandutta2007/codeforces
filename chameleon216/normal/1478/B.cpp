#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=110;

const int N=100;
int M,D;
char isL[MX];

char check(int x)
{
	while(x)
	{
		if(x%10==D)return 1;
		x/=10;
	}
	return 0;
}

int mian()
{
	scanf("%d%d",&M,&D);
	Fr(i,1,N)
	{
		if(check(i)){isL[i]=1;continue;}
		Fr(j,1,i-1)
		{
			if(isL[j]&&isL[i-j]){isL[i]=1;continue;}
		}
	}
	//Fr(i,1,N)if(!isL[i])printf("%d\n",i);
	Fr(i,1,M)
	{
		int q;
		scanf("%d",&q);
		if(q<=100&&isL[q]==0)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		mian();
		Fill(isL,0);
	}
	return 0;
}