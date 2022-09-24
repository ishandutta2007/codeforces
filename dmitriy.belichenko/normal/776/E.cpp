#include<iostream>
#include<math.h>
#define ll long long
using namespace std;
ll n,k;
ll phi(ll n)
{
	ll ans = n;
	for(ll i = 2; i * i < n + 1; i++)
		if(n % i == 0)
		{
		  	while(n % i == 0)
		  	{
		  	    n/=i;
		  	}
		  	ans /= i;
		  	ans *= (i-1);
		}
	if( n > 1) ans = ans / n * (n-1);
	return ans;
} 
signed main()
{
	cin >> n >> k;
	for(ll i = 1; i < k + 1; i+=2){
		n = phi(n);
		if(n==1)break;
	}
	cout << n % 1000000007 << "\n";
	return 0;
}