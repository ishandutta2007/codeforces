#include<iostream>
using namespace std;
int n,a,b;
int main()
{
	cin>>n>>a>>b;
	int mx=0,i;
	for(i=1;i<n;i++)
	{
		mx=max(mx,min(a/i,b/(n-i)));
	}
	cout<<mx;
	return 0;
}