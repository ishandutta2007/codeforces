#include<bits/stdc++.h>
using namespace std;
int n,a[100003],num[20004];
long long all=0,ans=0;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		all+=a[i];
	}
	num[all/n+1]=all%n;
	num[all/n]=n-all%n;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=all/n)
			if(num[all/n])
				ans=ans+all/n-a[i],
				num[all/n]--;
			else
				ans=ans+all/n+1-a[i],
				num[all/n+1]--;
		else
			if(num[all/n+1])
				ans=ans+a[i]-all/n-1,
				num[all/n+1]--;
			else
				ans=ans+a[i]-all/n,
				num[all/n]--;
	}
	cout<<ans/2;
}