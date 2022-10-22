#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=1100,MY=1000100;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int N,M,K,P,G[MX][MX];
int Sx[MX],Sy[MX];
ll Ax[MY],Ay[MY];

void Solve(int x[],int n,int m,ll res[])
{
	priority_queue<int> q;
	Fr(i,1,n)q.push(x[i]);
	ll sum=0;
	Fr(i,1,K)
	{
		int y=q.top();
		q.pop();
		sum+=y;
		q.push(y-m*P);
		res[i]=sum;
	}
}

int main()
{
	scanf("%d%d%d%d",&N,&M,&K,&P);
	Fr(i,1,N)Fr(j,1,M)
	{
		scanf("%d",&G[i][j]);
		Sx[i]+=G[i][j];
		Sy[j]+=G[i][j];
	}
	Solve(Sx,N,M,Ax);
	Solve(Sy,M,N,Ay);
	ll ans=-Inf;
	Fr(i,0,K)ans=max(ans,Ax[i]+Ay[K-i]-(ll)P*i*(K-i));
	printf("%lld\n",ans);
	return 0;
}