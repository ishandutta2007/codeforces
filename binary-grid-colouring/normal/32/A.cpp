#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];


int main()
{
	int n;int d;
	cin>>n>>d;
	vector<int>a(n+1);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(abs(a[i]-a[j])<=d)
			{
				ans++;			}
		}
	}
	cout<<2*ans<<endl;
	return 0;
}