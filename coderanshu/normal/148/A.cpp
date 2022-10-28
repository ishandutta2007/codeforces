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
    int k,l,m,n;
    long int d,i,c=0;
    cin>>k>>l>>m>>n>>d;
    for(i=1;i<=d;i++)
    {
    	if(i%k!=0 && i%l!=0 && i%m!=0 && i%n!=0)c++;
    }
    cout<<d-c;
	return 0;
}