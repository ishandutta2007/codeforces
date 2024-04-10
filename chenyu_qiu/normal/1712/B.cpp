#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll math(char a, char b)
{
	ll ans = 0;
	ans+=(b-'0')*10;
	ans+=(a-'0');
	//cout<<ans<<endl;
	return ans;
}
int main() {
	ll tt;
	cin>>tt;
	while(tt--)
	{
		ll n;
		cin>>n;
		if(n%2)
		{
			cout<<1<<' ';
			for (int i = 2; i <= n; ++i)
			{
				if(i%2)
					cout<<i-1<<' ';
				else
					cout<<i+1<<' ';
			}
		}
		else
		{
			for (int i = 1; i <= n; ++i)
			{
				if(i%2)
					cout<<i+1<<' ';
				else
					cout<<i-1<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}