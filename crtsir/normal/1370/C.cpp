#include<bits/stdc++.h>
using namespace std;
int T,n;
bool check(int x)
{
	for(int i=2;i<31;i++)
		if(pow(2,i)==x)
			return 1;
	return 0;
}
bool isprime(int x)
{
	if(x==1)return 0;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n==1||check(n)||(n%2==0&&isprime(n/2)))
			cout<<"FastestFinger\n";
		else
			cout<<"Ashishgup\n";
	}
}