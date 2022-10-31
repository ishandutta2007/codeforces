#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long ans=0;
	if(n%2==1)
	{
		if(n==1) ans=1;
		else ans=n*(n-1)*(n-2);
	}
	else{
		if(n==6)
			ans=4*3*5;
		else if(n==2) ans=2;
		else {
			ans=n*(n-1)*(n-3);
			if(n%3==0)
			{
				ans/=n;
				ans*=(n-2);
			}
		}
	}
	cout<<ans<<endl;
}