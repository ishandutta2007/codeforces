#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int a,b;
		cin>>a>>b;
		int delta=abs(a-b);
		int ans=0;
		ans+=delta/5;
		delta%=5;
		ans+=delta/2;
		delta%=2;
		ans+=delta;
		cout<<ans<<'\n';
	}
}