#include<bits/stdc++.h>
using namespace std ;

#define li long int 
int b[900];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    #endif
    int n,k,i,j,m;
    cin>>n>>k;
    int a[k];
    for(i=0;i<k;i++)
    {
    	cin>>a[i];
    	b[a[i]-1]=1;
    }
    for(i=0;i<k;i++)
    {
    	m=1;
    	cout<<a[i]<<" ";
    	for(j=0;m<n;j++)
    	{
    		if(b[j]==0)
    		{
    			cout<<j+1<<" ";b[j]=1;m++;
    		}
    	}
    	cout<<"\n";
    }
	return 0;
}