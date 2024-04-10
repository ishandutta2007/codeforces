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
    char a[11];
    cin>>a;
    int i;
    if(a[1]=='\0')
    {
        if(a[0]==49)cout<<"YES";
        else cout<<"NO";
        return 0;
    }
    if(a[0]!=49 || (a[1]!=49 && a[1]!=52))
    {
    	cout<<"NO";return 0;
    }
    for(i=2;a[i]!='\0';i++)
    {
    	if(a[i]!=49 && a[i]!=52)
    	{
    		cout<<"NO";return 0;
    	}
    	else
    	{
    		if(a[i]==52)
    		{
    			if(a[i-1]!=49 && a[i-2]!=49)
    			{
    				cout<<"NO";return 0;
    			}
    		}
    	}
    }
    cout<<"YES";
	return 0;
}