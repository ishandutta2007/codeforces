#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	long long ans=0;
	ans+=ceil(2*n/double(k))+ceil(5*n/double(k))+ceil(8*n/double(k));
	cout<<ans<<endl;
}