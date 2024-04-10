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
const int MX=450000;
int N;
ll w[MX],W;
bool cmp(ll a,ll b){return a>b;}
ll A[MX],C[MX],S[MX],sc;

int mian()
{
	scanf("%d%lld",&N,&W);
	Fr(i,1,N)scanf("%lld",w+i);
	sort(w+1,w+1+N,cmp);
	int cnt=0;
	Fr(i,1,N)
	{
		if(A[cnt]!=w[i])A[++cnt]=w[i];
		++C[cnt];
	}
	int ans=0;
	Fr(i,1,cnt)
	{
		int now=1;
		Fr(j,1,C[i])
		{
			while(1)
			{
				if(S[now]+A[i]<=W)
				{S[now]+=A[i];break;}
				++now;
			}
		}
		ans=max(ans,now);
	}
	printf("%d\n",ans);
	//Fr(i,1,ans)printf("%lld ",S[i]);putchar('\n');
	return 0;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		mian();
		Fr(i,1,N)w[i]=A[i]=C[i]=S[i]=0;
		W=N=0;
	}
}