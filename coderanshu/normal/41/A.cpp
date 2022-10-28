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
    char a[200],b[200];
    cin>>a>>b;
    if(strcmp(strrev(b),a)==0)
    	cout<<"YES";
    else cout<<"NO";
    return 0;
}