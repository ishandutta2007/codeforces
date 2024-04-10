#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <iterator>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <utility>
#include <functional>
#include <stack>
#include <deque>
#include <sstream>
using namespace std;

#define ll long long
#define mod 1000000007
#define ld long double
#define infinity (ll)1e18+1
#define PI 3.14159265358979

#define pdd pair<ld,ld>
#define pll pair<ll, ll>
#define pii pair<int,int>

#define MP make_pair
#define SZ size()
#define PB push_back

#define vi vector<int>//ll
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define vch vector<char>
#define vb vector<bool>
#define vld vector<ld>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 4000001
clock_t startTime;

int main()
{
	srand(time(NULL));
	startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	ll q;
	cin >> q;
	if (q == 1)
	{
		cout << 1 << endl << 0;
		return 0;
	}
	vch sieve;
	sieve.assign(MAXN, 1);
	sieve[0] = sieve[1] = 0;
	FOR(i, 2, MAXN)
		if (sieve[i] == 1)
			for (ll j = i*i; j < MAXN; j += i)
				sieve[j] = 0;

	vi primes;
	FOR(i, 2, MAXN)
		if (sieve[i] == 1)
			primes.push_back(i);

	vi factors, degrees;
	int d;
	FOR(i,0,primes.size())
		if (q%primes[i] == 0)
		{
			factors.push_back(primes[i]);
			d = 0;
			while (q%primes[i] == 0)
				d++, q /= primes[i];
			degrees.push_back(d);
		}

	if (q != 1)
		factors.push_back(q), degrees.push_back(1);

	
	int sum_degree = 0;
	for (auto d : degrees)
		sum_degree += d;

	if (sum_degree == 1)
	{
		cout << 1 << endl << 0;
		return 0;
	}

	if (sum_degree == 2)
		cout << 2;
	else
	{
		cout << 1 << endl;
		if (degrees[0] > 1)
			cout << factors[0] * factors[0];
		else
			cout << factors[0] * factors[1];
	}
	

	return 0;
}
//don't forget about MAXN, mod and infinity