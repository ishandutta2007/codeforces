#include<cstdio>
#include<vector>
#include<algorithm>
#define N 300010
using namespace std;
vector<int>v[N];
int s,a[5][N],dp[N],dp2[N],n[5],m,x,y,len;
struct st{
	int k[N][50];
	int n,f,lg[N];
	#define pow2(x) (1<<(x))
	#define max(a,b) (a>b?a:b)
	void init(int xxx,int *p)
	{
		n=xxx;
		for(int i=1;i<=n;i++)
		{
			if(i>1) lg[i]=lg[i/2]+1;
			p++;
			k[i][0]=*p;
		}
		for(int j=1;j<=lg[n];j++)
		{
			for(int i=1;i<=n;i++)
			{
				k[i][j]=min(k[i+pow2(j-1)][j-1],k[i][j-1]);
			}
		}
	}
	int getmin(int a,int b)
	{
		if(b<a) return 0x3f3f3f3f;
		f=lg[b-a+1];
		return min(k[a][f],k[b-pow2(f)+1][f]);
	}
} k;
int main()
{
	scanf("%d%d%d%d",&n[1],&n[2],&n[3],&n[4]);
	for(int i=1;i<=4;i++)
		for(int j=1;j<=n[i];j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n[1];i++) dp[i]=a[1][i];
	for(int col=2;col<=4;col++)
	{
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&x,&y),
			v[y].push_back(x);
		for(int i=1;i<=n[col];i++) v[i].push_back(0),v[i].push_back(n[col-1]+1),sort(v[i].begin(),v[i].end());
		k.init(n[col-1],dp);
		for(int i=1;i<=n[col];i++)
		{
			len=v[i].size();
			dp2[i]=0x3f3f3f3f;
			for(int j=1;j<len;j++)
			{
				dp2[i]=min(dp2[i],k.getmin(v[i][j-1]+1,v[i][j]-1)+a[col][i]);
			}
		}
		for(int i=1;i<=n[col];i++)
			dp[i]=dp2[i],v[i].clear();
	}
	s=0x3f3f3f3f;
	for(int i=1;i<=n[4];i++) s=min(s,dp[i]);
	printf("%d",s>=0x3f3f3f3f?-1:s);
}