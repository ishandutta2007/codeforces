#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,m;cin>>n>>m;int t=n*m/2;
	if (n==1 || m==1) cout<<n*m;
	else if (n==2 || m==2)
	{
		if (t%4==0) cout<<t;
		else cout<<(t/2)*2+2;
	}
	else cout<<t+((n*m)%2);
}