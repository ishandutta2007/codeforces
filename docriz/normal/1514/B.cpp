#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
int T,n,k;
const int mod=1e9+7;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		int ans=1;
		for(int i=1;i<=k;i++)ans=1ll*ans*n%mod;
		printf("%d\n",ans);
	}
	return 0;
}