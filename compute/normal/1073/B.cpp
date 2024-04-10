#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int a[maxn],b[maxn];
int mp[maxn];
int ans[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mp[a[i]]=i;
	}
	int top=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(mp[b[i]]<top) ans[i]=0;
		else{
			ans[i]=mp[b[i]]-top;
			top=mp[b[i]];
		}
	}
	printf("%d",ans[1]);
	for(int i=2;i<=n;i++)
		printf(" %d",ans[i]);
	printf("\n");
	
	
}