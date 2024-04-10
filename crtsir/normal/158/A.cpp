#include<iostream>
using namespace std;
int main()
{
	int n,k,ans=0;
	cin>>n>>k;
	int a[n+1];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]>=a[k]&&a[i]>0)
			ans++;
	cout<<ans;
}