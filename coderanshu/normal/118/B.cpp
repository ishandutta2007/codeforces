#include<bits/stdc++.h>
using namespace std ;

#define li long int 
int func(int n,int r)
{
	int i;
	for(i=1;i<=2*n-2*r;i++)
		cout<<" ";
	if(r==0)
	{
		cout<<0;return 0;
	}
	for(i=0;i<=r;i++)
		cout<<i<<" ";
	for(i=r-1;i>0;i--)
		cout<<i<<" ";
	cout<<0;
	return 0;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    #endif
    int n,i;
    cin>>n;
    for(i=0;i<=n;i++)
    {
    	func(n,i);cout<<"\n";
    }
    for(i=n-1;i>=0;i--)
    {
    	func(n,i);cout<<"\n";
    }
    return 0;
}