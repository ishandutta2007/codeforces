#include<iostream>
using namespace std;
int main()
{
	long long m,n,a;
	cin>>m>>n>>a;
	long long x=m/a,y=n/a;
	if (x*a<m) x++;
	if (y*a<n) y++;
	long long ans=x*y;
	cout<<ans;
	return 0;
}