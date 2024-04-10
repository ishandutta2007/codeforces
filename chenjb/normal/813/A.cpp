#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,m;
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		sum+=x;
	}
	int ans=-1;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin>>l>>r;
		if (sum<=r)
		{
			ans=max(l,sum);
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}