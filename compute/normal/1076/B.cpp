#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	if(n%2==0)
	{
		cout<<n/2<<endl;
	}
	else{
		long long flag=-1;
		for(long long i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				flag=i;
				break;
			}
		}
		if(flag==-1) flag=n;
		long long ans=0;
		ans=1+(n-flag)/2;
		cout<<ans<<endl;
	}
}