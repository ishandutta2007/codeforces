#include<bits/stdc++.h>
using namespace std;
long long n,a[503],ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(n<=3)
	{
		for(int i=0;i<n;i++)
			ans|=a[i];
		cout<<ans;
		return 0;
	}
	for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++)
			for(int k=0;k<n;k++)
				ans=max(ans,(a[i]|a[j]|a[k]));
	cout<<ans;
}