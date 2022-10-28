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

    int n,num,count=0;
    cin>>n;
    int ev=0,od=0;
    for(int i=0;i<n;i++)
    {
    	cin>>num;
    	count+=num;
    	if(num%2==0)
    		ev++;
    	else od++;
    }
    if(count%2)
    	cout<<od;
    else cout<<ev;
	return 0;
}