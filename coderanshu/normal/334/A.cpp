#include<bits/stdc++.h>
using namespace std ;

#define li long int 

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    #endif

    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n/2;j++)
    		cout<<(i-1)*n/2+j<<" ";
    	for(j=0;j<n/2;j++)
    		cout<<n*n-i*n/2+1+j<<" ";
    	cout<<"\n";
    }
	return 0;
}