#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <map>
#include <iostream>
using namespace std;
#define infinity 1000000000
#define ll long long
#define mod 1234567891
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)

bool isPrime(ll n)
{
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i*i <= n; ++i)
		if (n%i == 0)return false;
	return true;
}


int main()
{
	ll n;
	cin >> n;

	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	if (n == 2)
	{
		cout << 2;
		return 0;
	}

	if(n%2==1)
		cout <<(n*(n-1)*(n-2));
	else
	{
		ll x = n*(n - 1)*(n - 2) / 2;
		if (n % 3 != 0)
			x = max(x,n*(n - 1)*(n - 3));
		else
		{
			x = max(x, (n - 1)*(n - 2)*(n - 3));
			if (x % 5 != 0)
				x = max(x, n*(n - 1)*(n - 5));

		}
		cout << x;
	}
	return 0;
}