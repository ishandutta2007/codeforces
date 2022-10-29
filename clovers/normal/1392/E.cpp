#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;
typedef pair<int,int> pii;
#define mk make_pair

ll n,a[30][30];
ll del[55];

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ll tmp1=0,tmp2=0;
			if(i==1||j==n)
			{
				a[i][j]=0;
				continue;
			}
			for(int k=1;k<=j;k++) tmp1+=a[1][k];
			for(int k=1;k<i;k++) tmp1+=a[k][j];
			for(int k=1;k<i;k++) tmp2+=a[k][1];
			for(int k=1;k<=j;k++) tmp2+=a[i-1][k];
			ll delta=tmp2-tmp1;
			a[i][j]=a[i-1][j+1]+delta+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) 
		{
			printf("%lld ",a[i][j]);
		}
		puts("");
	}
	fflush(stdout);
	
	int q;
	scanf("%d",&q);
	vector<pii> ans; 
	while(q--)
	{
		ans.clear();
		ll sum; scanf("%lld",&sum);
		int nowx=n,nowy=n;
		ans.push_back(mk(n,n));
		while(nowx!=1||nowy!=1)
		{
			if(nowx==1) 
			{
				for(int i=nowy-1;i>=1;i--)
				{
					ans.push_back(mk(1,i));
				}
				nowy=1;
				continue;
			}
			if(nowy==1)
			{
				for(int i=nowx-1;i>=1;i--)
				{
					ans.push_back(mk(i,1));
				}
				nowx=1;
				continue;
			}
			ll tmp1=0;
			for(int k=1;k<nowy;k++) tmp1+=a[1][k];
			for(int k=1;k<nowx;k++) tmp1+=a[k][nowy-1];
			if(sum>=a[nowx][nowy-1]+tmp1) 
			{
				sum-=a[nowx][nowy-1];
				ans.push_back(mk(nowx,nowy-1));
				nowy--;
			}
			else
			{
				sum-=a[nowx-1][nowy];
				ans.push_back(mk(nowx-1,nowy));
				nowx--;
			}
		}
		for(int i=n+n-2;i>=0;i--)
		{
			printf("%d %d\n",ans[i].first,ans[i].second);
		}
		fflush(stdout);
	}
	return 0;
}