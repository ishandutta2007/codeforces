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
    string a,b;
    cin>>a>>b;
    if(a.length()!=b.length())
    {
    	cout<<"NO";
    	return 0;
    }
    else
    {
    	long int i;bool c1=0,c2=0;
    	for(i=0;i<a.length();i++)
    	{
    		if(a[i]=='1'){c1=1;break;}
    	}
    	for(i=0;i<b.length();i++)
    	{
    		if(b[i]=='1'){c2=1;break;}
    	}
    	if(c1^c2)cout<<"NO";
    	else cout<<"YES";
    }
	return 0;
}