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

    char a[20];
    cin>>a;
    int i,c=0;
    for(i=0;a[i]!='\0';i++)
    {
    	if(a[i]-48==4 || a[i]-48==7)
    		c++;
    }
    if(c==4 || c==7)
    	cout<<"YES";
    else cout<<"NO";
	return 0;
}