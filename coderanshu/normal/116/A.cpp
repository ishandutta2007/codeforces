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

    int n,a,b,c=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a>>b;
    	if(b-a<=0)
    		ans=max(c,ans);
    	c+=b-a;
    }
    cout<<ans;
	return 0;
}