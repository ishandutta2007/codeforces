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

    string s;
    int n,i,num=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
    	cin>>s;
    	if(s[0]!='X')
    	{
    		if(s[0]=='+')num++;
    		else num--;
    	}
    	else
    	{
    		if(s[1]=='+')num++;
    		else num--;
    	}
    }
    cout<<num;
	return 0;
}