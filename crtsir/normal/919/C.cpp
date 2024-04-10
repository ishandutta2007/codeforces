#include<iostream>
using namespace std;
string c[2001];
int main()
{
	int m,n,k;
	cin>>m>>n>>k;
	for(int i=0;i<m;i++)
		cin>>c[i];
	int ans=0;
	if(k==1)
	{
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				if(c[i][j]=='.')
					ans++;
		cout<<ans;
		return 0;
	}
	for(int i=0;i<m;i++)
	{
		int js=0;
		for(int j=0;j<n;j++)
			if(c[i][j]=='.')
				js++;
			else
			{
				ans+=max(0,js-k+1);
				js=0;
			}
		ans+=max(0,js-k+1);
	}
	for(int i=0;i<n;i++)
	{
		int js=0;
		for(int j=0;j<m;j++)
			if(c[j][i]=='.')
				js++;
			else
			{
				ans+=max(0,js-k+1);
				js=0;
			}
		ans+=max(0,js-k+1);
	}
	cout<<ans;
}