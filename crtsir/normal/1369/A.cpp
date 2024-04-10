#include<bits/stdc++.h>
using namespace std;
int T,n;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n%4)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}