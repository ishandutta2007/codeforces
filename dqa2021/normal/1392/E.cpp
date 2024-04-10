#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int n,q;
ll w[30][30];
int main()
{
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
		for (int j=1;j<=n;j++){
			ll t=1LL<<i+j-3;
			int u=i,v=j;
			while (u<=n&&v>0){
				w[u][v]+=t;
				u++,v--;
			}
			u=i,v=j-1;
			while (u<=n&&v>0){
				w[u][v]-=t;
				u++,v--;
			}
		}
	ll mx=-1e18,mn=-mx;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			mx=max(mx,w[i][j]),mn=min(mn,w[i][j]);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			printf("%I64d%c",w[i][j]-mn," \n"[j==n]);
	fflush(stdout);
	scanf("%d",&q);
	while (q--){
		ll x; scanf("%I64d",&x); x+=mn*(n*2-1);  //I64d
		printf("1 1\n"); int u=1,v=1;
		for (int i=0;i<n-1<<1;i++){
			if (x>>i&1) u++;
			else v++;
			printf("%d %d\n",u,v);
		}
		fflush(stdout);
	}
	return 0;
}