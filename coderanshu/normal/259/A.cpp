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
    int i,j;
    char a[8];
    int ans=1,w,b;
    for(i=0;i<8;i++)
    {
    	w=b=0;
    	for(j=0;j<8;j++)
    	{
    		cin>>a[j];
    	}
    	for(j=0;j<7;j++)
    	{
    		if(a[j]==a[j+1])
    			ans=0;
    		if(a[j]=='W')w++;
    		else if(a[j]=='B')b++;
    	}
    	if(a[7]=='B')b++;
    	else w++;
    	if(w!=b)ans=0;

    }
    if(ans)cout<<"YES";
    else cout<<"NO";
	return 0;
}