#include<bits/stdc++.h>
using namespace std;
int m,num[10],n,a,ans;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		num[a-1]++;
	}
	for(int i=0;i<m-1;i++)
		for(int j=i+1;j<m;j++)
			ans+=num[i]*num[j];
	cout<<ans;
}