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
	ll n, k;
	cin >> n >> k;

	vector<ll> primes;
	FOR(i, 2, n + 1)
		if (isPrime(i))
			primes.push_back(i);

	int num = 0;
	FOR(i, 0, primes.size())
	{
		FOR(k, 0, i)
		{
			if (primes[k] + primes[k + 1] + 1 == primes[i])
			{
				num++;
				break;
			}
		}
	}

	if (num >= k)cout << "YES";
	else cout << "NO";
	return 0;
}