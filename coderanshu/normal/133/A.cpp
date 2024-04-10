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
    cin>>s;
    int f=0;
    for(int i=0;i<s.length();i++)
    {
    	if(s[i]=='H' || s[i]=='Q' || s[i]=='9')
    		f=1;
    }
    if(f)cout<<"YES";
    else cout<<"NO";
	return 0;
}