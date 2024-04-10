#include<bits/stdc++.h>
using namespace std;
int check(long long i)
{
	int ans=0;
	while(i!=0)
	{
		ans+=i%10;
		i=i/10;
	}
	return ans;
}
int main()
{
	int n,numbers=0;
	cin>>n;
	long long i=1;
	for(;numbers<n;i+=9)
		if(check(i)==10)numbers++;
	cout<<i-9;
}