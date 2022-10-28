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

    int n,i,num;
    double sum;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    	cin>>num;
    	sum+=num;
    }
    cout<<fixed<<setprecision(10)<<sum/n;
	return 0;
}