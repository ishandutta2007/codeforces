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

    string a,b,c;
    cin>>a>>b>>c;
    int i,j,f;
    if(a.length()+b.length()!=c.length())
    {
    	cout<<"NO";
    	return 0;
    }
    for(i=0;i<a.length();i++)
    {
    	f=0;
    	for(j=0;j<c.length();j++)
    	{
    		if(a[i]==c[j])
    		{
    			c[j]='0';f=1;break;
    		}
    	}
    	if(f==0)
    	{
    		cout<<"NO";return 0;
    	}
    }
    for(i=0;i<b.length();i++)
    {
    	f=0;
    	for(j=0;j<c.length();j++)
    	{
    		if(b[i]==c[j])
    		{
    			c[j]='0';f=1;break;
    		}
    	}
    	if(f==0)
    	{
    		cout<<"NO";return 0;
    	}
    }
    cout<<"YES";
	return 0;
}