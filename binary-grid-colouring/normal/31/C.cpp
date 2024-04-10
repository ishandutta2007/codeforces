#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

int l[5678],r[5678];
int a[5678];
int num,ans;
int main()
{
	int n;
	cin>>n;
	
	num = 0,ans = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(l[i] < r[j] && l[j] < r[i])
			{
				a[i]++;
				a[j]++;
				num++;
			}
		}
	}
//	cout<<"num="<<num<<endl;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==num)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==num)
		{
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}