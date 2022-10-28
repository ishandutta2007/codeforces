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
    long int n,sum=0,a,b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		sum+=a;
	}
	long int temp1=n-sum/1000,temp2=sum%1000;
	temp1-=(temp2>500);
	for(int i=1;i<=temp1;i++)
	{
		cout<<"A";
	}
	for(int i=temp1+1;i<=n;i++)
		cout<<"G";
	return 0;
}