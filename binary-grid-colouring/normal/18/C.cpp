#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[123456];
int sum[123456];
int main()
{
	int n;
	cin>>n;;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=a[i]+sum[i-1];
	}
	int ans = 0;
	for(int i=1;i<=n-1;i++)
	{
		if(sum[i]==sum[n]-sum[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
 }