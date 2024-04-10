#include<iostream>
using namespace std;
#define ll long long
ll a[30000000],cnt;
int main()
{
	ll n,k,i;
	cin>>n>>k;
	for(i=1;i*i<n;++i)if(n%i==0)
	{
		if(!--k){cout<<i;return 0;}
		a[cnt++]=n/i;
	}
	if(i*i==n)if(!--k){cout<<i;return 0;}
	cout<<(cnt<k?-1:a[cnt-k]);
}