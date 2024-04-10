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
    int n,x,i;
    cin>>n;
    int a[5000]={};
    for(i=0;i<n;i++)
    {
    	cin>>x;
    	a[x-1]=1;
    }
    int c=0;
    for(i=0;i<n;i++)
    {
    	if(a[i]==0)
    		c++;
    }
    cout<<c;
	return 0;
}