#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[210000],ans[210000];
int main()
{
	memset(a,0,sizeof(a));
	memset(ans,0,sizeof(a));
	int n,k,q;
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		a[l]++;
		a[r+1]--;
	}
	for(int i=1;i<=200000;i++)a[i]+=a[i-1];
	for(int i=1;i<=200000;i++)
		if (a[i]>=k)ans[i]=1;
	for(int i=1;i<=200000;i++)ans[i]+=ans[i-1];
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",ans[r]-ans[l-1]);
	}
	return 0;
}