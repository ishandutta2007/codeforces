#include<bits/stdc++.h>
using namespace std;
int a[100012],n;
bool isprime(int x)
{
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return false;
	return true;
}
bool check(int x)
{
	for(int i=0;i<x;i++)
	{
		bool yes=true;
		for(int j=i;j<n;j+=x)
			if(!a[j])
				yes=false;
		if(yes)
			return true;
	}
	return false;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=3;i<=n;i++)
		if(n%i==0)
			if(check(n/i))
			{
				cout<<"YES";
				return 0;
			}
	cout<<"NO";
}