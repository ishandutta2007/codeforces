#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long b;
	cin>>b;
	long long ans=1;
	for(long long i=2;i*i<=b;i++)
	{
		if(b%i==0)
		{
			int cnt=0;
			while(b%i==0)
			{
				cnt++;b/=i;
			}
			ans*=(cnt+1);
		}
	}
	if(b>1) ans*=2;
	cout<<ans<<endl;
}