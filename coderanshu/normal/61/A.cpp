#include<bits/stdc++.h>
using namespace std ;

#define li long int 

int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    #endif

	string a,b;
	cin>>a>>b;
	for(int i=0;i<a.length();i++)
	{
		a[i]=(a[i]-48)^(b[i]-48)+48;
	}
	cout<<a;

	return 0;
}