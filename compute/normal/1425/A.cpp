#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		ll c0=0,c1=0;
		ll n;
		cin>>n;
		int fg=0;
		while(n)
		{
			ll cur=0;
			if(n==4)
				cur=2;
			else{
				if(n&1) cur=1;
				else{
					if(n/2%2==0)
						cur=1;
					else cur=n/2;
				}
			}
			n-=cur;
			if(!fg) c0+=cur;
			fg^=1;
		}
		cout<<c0<<'\n';
	}
}