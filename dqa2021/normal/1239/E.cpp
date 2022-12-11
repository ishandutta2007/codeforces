#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std;

int n,w[55];
bitset<1250001> dp[52][26];
int totw;
int ans=0x7fffffff,ans1,ans2;
int stk1[30],stk1top,stk2[30],stk2top;
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("A.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",w+i),totw+=w[i];
	for (int i=1;i<=n;i++) scanf("%d",w+n+i),totw+=w[i+n];
	sort(w+1,w+n+n+1);  //caution n and 2n
	//puts("w[]:"); for (int i=1;i<=n+n;i++) printf("%d ",w[i]); putchar('\n');
	//printf("totw: %d\n",totw);
	dp[n+n+1][0][0]=1;
	for (int i=n+n+1;i>2;i--)
	{
		for (int j=0;j<=n+n-i+1&&j<n;j++)  //j<n
		{
			dp[i-1][j]|=dp[i][j];
			dp[i-1][j+1]|=(dp[i][j]<<w[i-1]);
		}
	}
	for (int i=2;i<=n+n;i++)
	{
		for (int j=0;j<=totw;j++)
			if (dp[i][n][j])
			{
				int subans=max(j+w[1],totw-j+w[i]);
				if (subans<ans)
				{
					ans=subans,ans1=i,ans2=j;
				}
			}
	}
	//printf("ans %d\n",ans);
	//printf("%d\n",ans);
	//printf("ans1 %d ans2 %d\n",ans1,ans2);
	stk2[++stk2top]=w[1];
	for (int i=2;i<ans1;i++) stk2[++stk2top]=w[i];
	for (int i=ans1,j=n,k=ans2;i<=n+n;)  //k used
	{
		if (/*dp[i+1][j][k]*/!(j&&k>=w[i]&&dp[i+1][j-1][k-w[i]]))
		{
			//printf("A\n");
			stk2[++stk2top]=w[i];
			i++;
		}
		else
		{
			//printf("B\n");
			stk1[++stk1top]=w[i];
			j--; k-=w[i]; i++;
		}
	}
	sort(stk1+1,stk1+stk1top+1);
	sort(stk2+1,stk2+stk2top+1);
	for (int i=1;i<=n;i++) printf("%d ",stk1[i]); putchar('\n');
	for (int i=n;i;i--) printf("%d ",stk2[i]); putchar('\n');
	return 0;
}