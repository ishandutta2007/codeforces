#include<iostream>
using namespace std;
int main()
{
	long long n,k,x,min1,min2,min3=9000000000000000000;
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>x;
		if(n%x<min3)
		{
			min1=i+1;
			min2=n/x;
			min3=n%x;
		}
	}
	cout<<min1<<' '<<min2;
}