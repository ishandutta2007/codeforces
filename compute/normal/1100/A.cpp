#include<bits/stdc++.h>
using namespace std;
int arr[200];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		int e=0,s=0;
		for(int j=1;j<=n;j++)
		{
			if(j>=i&&(j-i)%k==0)
				continue;
			if(arr[j]==1) e++;
			else s++;
		}
		ans=max(ans,abs(e-s));
	}
	cout<<ans<<endl;
}