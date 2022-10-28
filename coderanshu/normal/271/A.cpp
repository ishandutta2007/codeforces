#include<bits/stdc++.h>
using namespace std ;

#define li long int 
bool is_distinct(int n)
{
	int k[4],i=0;
	while(n!=0)
	{
		k[i++]=n%10;
		n/=10;
	}
	sort(k,k+4);
	if(k[1]-k[0]==0 || k[2]-k[1]==0 || k[3]-k[2]==0)
		return false;
	return true;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE

    freopen("inputf.in", "r", stdin);
    freopen("outputf.in", "w", stdout);

    #endif
    int n;
    cin>>n;
    n++;
    while(!is_distinct(n))
    {
    	n++;
    }
    cout<<n;
	return 0;
}