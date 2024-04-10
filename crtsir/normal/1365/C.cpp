#include<bits/stdc++.h>
using namespace std;
int n,a[200003],tmp,cnt[200003],ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		a[tmp-1]=i;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		cnt[(a[tmp-1]-i+n)%n]++;
	}
	for(int i=0;i<n;i++)
		ans=max(ans,cnt[i]);
	cout<<ans;
}