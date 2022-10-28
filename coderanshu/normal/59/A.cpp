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
    int i,c=0;
    string s;
    cin>>s;
    for(i=0;i<s.length();i++)
    {
    	if(s[i]>=97 && s[i]<=122)
    		c++;
    }
    if(2*c>=s.length())
    {
    	for(i=0;i<s.length();i++)
    		s[i]|=' ';
    }
    else 
    {
    	for (i = 0; i <s.length(); ++i)
    	{
    		s[i]&='_';
    	}
    }
    cout<<s;

	return 0;
}