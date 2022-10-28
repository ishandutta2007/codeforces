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

    long int x,y,z;
    cin>>x>>y;
    z=abs(x)+abs(y);
    if(x>0 && y>0)	
    	cout<<0<<" "<<z<<" "<<z<<" "<<0;
    if(x>0 && y<0)	
    	cout<<0<<" "<<(-1)*z<<" "<<z<<" "<<0;
    if(x<0 && y>0)	
    	cout<<(-1)*z<<" "<<0<<" "<<0<<" "<<z;
    if(x<0 && y<0)	
    	cout<<(-1)*z<<" "<<0<<" "<<0<<" "<<(-1)*z;
	return 0;
}