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
    int x,n,num,sum=0,i;
    cin>>n>>x;
    for(i=0;i<n;i++)
    {
    	cin>>num;
    	sum+=num;
    }
    cout<<abs(sum)/x+(sum%x!=0);
	return 0;
}