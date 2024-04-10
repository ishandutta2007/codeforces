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
    char a[200];
    int i,j;
    cin>>a;
    for(i=0;a[i];i++)
    {
    	j=i;
    	while(a[i]==a[j] && a[i])i++;
    	if(i-j>=7)
    	{
    		cout<<"YES";return 0;
    	}
    	i--;
    }
    cout<<"NO";
    return 0;
}