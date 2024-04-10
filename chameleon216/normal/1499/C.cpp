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
const int MX=220000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int N;
ll A[MX];

int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",A+i);
	ll sum[2]={0,0},cnt[2]={0,0},mn[2]={Inf,Inf};
	ll Ans=Inf;
	Fr(i,1,N)
	{
		int t=i&1;
		sum[t]+=A[i],cnt[t]++,mn[t]=min(mn[t],A[i]);
		if(i>1)
		{
			ll ans=0;
			Fr(j,0,1)
				ans+=sum[j]+(N-cnt[j])*mn[j];
		//	printf("%lld\n",ans);
			Ans=min(Ans,ans);
		}
	}
	printf("%lld\n",Ans);
	return 0;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)mian();
	return 0;
}