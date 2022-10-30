#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<22;
int cnt[maxn];
int arr[maxn];
int vis[maxn];
void Insert(int x,int id)
{
	if(cnt[x]>=2||vis[x]==id) return;
	cnt[x]++;
	vis[x]=id;
	for(int j=21;j>=0;j--)
	{
		if(x>>j&1)
			Insert(x^(1<<j),id);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		int s=0;
		for(int j=21;j>=0;j--)
		{
			if(!(arr[i]>>j&1))
			{
				if(cnt[s|(1<<j)]>=2)
					s|=(1<<j);
			}
		}
		if(i<=n-2)
			ans=max(ans,arr[i]|s);
		Insert(arr[i],i);
	}
	printf("%d\n",ans);
}