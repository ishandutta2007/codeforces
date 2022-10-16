#include<iostream>
using namespace std;
int main()
{
	int n,maxv=0,yuan=0;
	cin>>n;
	int a[n][2];
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1];
		maxv=max(maxv,yuan+a[i][1]-a[i][0]);
		yuan+=a[i][1]-a[i][0];
	}
	cout<<maxv;
}