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

    int n,num;
    cin>>n;
    int m,M,count=0;
    cin>>num;
    m=M=num;
    for(int i=0;i<n;i++)
    {
    	cin>>num;
    	if(num>M)
    	{
    		M=num;
    		count++;
    	}
    	else if(num<m)
    	{
    		m=num;
    		count++;
    	}
    }
    cout<<count;
	return 0;
}