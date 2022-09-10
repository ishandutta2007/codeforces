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

ll n;
vector<int> primes;
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
	cin >> n;
	for (int i = 2; i <= 1500; ++i)
	{
		if (isPrime(i))
			primes.push_back(i);
	}

	int counter = 0;
	FOR(i, 6, n + 1)
	{
		bool b = false;
		FOR(j, 0, primes.size())
		{
			if (i%primes[j] == 0)
			{
				int t = i;
				while (t%primes[j] == 0)
					t /= primes[j];

				if (t == 1)
				{
					b == false;
					break;
				}
				int oldT = t;
				FOR(k, 0, primes.size())
				{
					t = oldT;
					if (t%primes[k] == 0)
					{
						while (t%primes[k] == 0)
							t /= primes[k];

						if (t == 1)
						{
							b = true;
							break;
						}
					}
				}
			}
		}

		if (b)
			counter++;
	}


	cout << counter;
	return 0;
}