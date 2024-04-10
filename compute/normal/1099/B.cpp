#include<iostream>
#include<cmath>
using namespace std;
long long solve(long long n)
{
	long long ret=0x3f3f3f3f;
	for(long long i=1;i<=sqrt(n);i++)
	{
		long long another=ceil(double(n)/i);
		ret=min(ret,another+i);
	}
	return ret;
}
int main()
{
	long long n;
	cin>>n;
	cout<<solve(n)<<endl;
}