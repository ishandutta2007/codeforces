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

    int n,m,i=1;
    cin>>n>>m;
    m=m%(n*(n+1)/2);
    while(m>=i)
    {
    	m-=i;i++;
    }
    cout<<m;
	return 0;
}