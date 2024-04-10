#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=(int)(2e9);
const ll INF=(ll)(5e18);
const int N=300010;

int T,n,m,a[305][305];
vector<int> v[10200];

int main()
{
	cin>>T;
	while(T--)
	{
		int sum=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+m;i++) v[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a[i][j]);
				if(i+j==n+m+2-i-j) continue;
				v[min(i+j,n+m+2-i-j)].push_back(a[i][j]);
			}
		}
		for(int i=2;i<=n+m;i++)
		{
			if((int)v[i].size()==0) continue;
			int len=(int) v[i].size(),now=0;
			for(int j=0;j<len;j++) now+=v[i][j];
			sum+=min(now,len-now);
		}
		printf("%d\n",sum);
	}
	return 0;
}