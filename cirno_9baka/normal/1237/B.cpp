#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,k,i,a[100005],b[100005],mx,p[100005],ans;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		p[b[i]]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(p[a[i]]<mx)
			ans++;
		mx=max(mx,p[a[i]]);
	}
	cout<<ans;
}