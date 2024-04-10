#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#define LL long long 
#define inf 1000000007
using namespace std;
int tot;
LL n,k;
LL ans;
int x[32],y[32];
int a[32][100000];
int main()
{
	//freopen("1.in","r",stdin);

	cin>>n>>k;
	if (k==1)
	{
		cout<<n*(n+1)/2<<endl;
		return 0;
	}
	tot=0;
	int tt=round(sqrt(k));
	for(int i=2;i<=tt;i++)
		if (k%i==0)
		{
			x[++tot]=i;
			y[tot]=0;
			while (k%i==0)y[tot]++,k/=i;
		}
	if (k!=1)x[++tot]=k,y[tot]=1;
	for(int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		for(int j=1;j<=tot;j++)
		{
			a[j][i]=0;
			while (tmp%x[j]==0)a[j][i]++,tmp/=x[j];
		}
	}
	int flag=1;
	for(int i=1;i<=tot;i++)
	{
		a[i][0]=0;
		for(int j=1;j<=n;j++)a[i][j]+=a[i][j-1];
		if (a[i][n]<y[i])flag=0;
	}
	if (!flag)
	{
		cout<<0<<endl;
		return 0;
	}

	ans=0;
	int tail=0;
	for(int head=0;head<=n;head++)
	{
		flag=1;
		for(int i=1;i<=tot;i++)
		{
			while (tail<n&&a[i][tail]-a[i][head]<y[i])tail++;
			if (a[i][tail]-a[i][head]<y[i])flag=0;
		}
		if (!flag)break;
		ans+=(n-tail+1);
	}
	cout<<ans<<endl;
	return 0;
}