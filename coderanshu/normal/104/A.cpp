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
    int n;
	cin>>n;
	if(n>21 || n<=10)
		cout<<0;
	else if(n==20)
		cout<<15;
	else cout<<4;

	return 0;
}