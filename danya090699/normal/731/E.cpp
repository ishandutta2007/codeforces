#include <iostream>
#include <fstream>
#define int long long
using namespace std;
main()
{
	ifstream in("input.txt");
	int n, ma;
	cin>>n;
	int tu[n+1], dp[n];
	tu[0]=0;
	for(int a=1; a<=n; a++)
	{
		cin>>tu[a];
		tu[a]+=tu[a-1];
	}
	dp[n-1]=0;
	ma=tu[n];
	for(int a=n-2; a>=0; a--)
	{
		dp[a]=ma;
		ma=max(ma, tu[a+1]-dp[a]);
	}
	cout<<dp[0];
}