#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j] = 1+(i+j)%(n-1);
		}
	}
	for(int i=0;i<n;i++)
	{
		a[n-1][i] = a[i][n-1] = a[i][i];
	}
	for(int i=0;i<n;i++)
	{
		a[i][i] = 0;
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i][0];
		for(int j=1;j<n;j++)
		{
			cout<<" "<<a[i][j];
		}
		cout<<endl; 
	}
	return 0;
}