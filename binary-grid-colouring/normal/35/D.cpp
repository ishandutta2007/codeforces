#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,X;
	int a[123];
	int ans = 0;
	cin>>n>>X;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i] *= (n-i);
	}
	sort(a,a+n);
	for(int i=0;i < n && X>=a[i];i++)
	{
		X-=a[i];
		ans++;
	}
	cout<<ans<<endl;
	return 0;
 }