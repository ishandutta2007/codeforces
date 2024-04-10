#include<iostream>
using namespace std;
int main()
{
	int n,ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int temp,tot=0;;
		for (int j=1;j<=3;j++)
		{
			cin>>temp;
			tot+=temp;
		}
		if (tot>=2)ans++;
	}
	cout<<ans;
	return 0;
}