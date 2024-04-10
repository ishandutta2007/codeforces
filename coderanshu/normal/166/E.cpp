#include<bits/stdc++.h>
using namespace std ;

#define li long int
#define modulo 1000000007 
int main()
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    #endif
    long int n,i=3;
    long long int x,y,temp;
    x=0;y=3;
    cin>>n;
    if(n==1)cout<<x;
    else if(n==2)cout<<y;
    else
    {
    while((i++)<=n)
    {
    	temp=((3*x)%modulo + (2*y)%modulo)%modulo;
    	x=y;y=temp;
    }
    cout<<temp;
	}	
	return 0;
}