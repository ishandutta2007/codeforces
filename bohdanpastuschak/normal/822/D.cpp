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
#define vs vector<string>

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define RFOR(i,b,a) for(ll i = (b) - 1; i >= (a); --i)
#define REPEAT(i) FOR(counter1234,0,i)
#define ALL(a) a.begin(), a.end()
#define X first
#define Y second
#define MAXN 5000001

ll power(ll n, ll to, ll modulo = mod)
{
	if (to == 0) return 1;
	if (to == 1) return n%modulo;
	int exp = 1;
	ll ans = n;
	while (2 * exp <= to)
	{
		ans *= ans;
		ans %= modulo;
		exp *= 2;
	}
	return ((ans*power(n, to - exp, modulo)) % modulo);
}

/*
vpll dist;
vll l, r, cost;

int f(pii a, pii b)
{
	if (a.first < b.first)
		return 1;
	if (a.first > b.first)
		return 0;
	if (cost[a.second] < cost[b.second])
		return 1;
	else
		return 0;
}

ll bin(ll v, ll l, ll r)
{
	if (r - l <= 1)
		if (dist[l].first == v)
			return l;
		else
			if (dist[r].first == v)
				return r;
			else
				return -1;

	ll m = (l + r) / 2;

	if (dist[m].first >= v)
		return bin(v, l, m);
	else
		return bin(v, m, r);			
}
*/

ll t;
ll l;
ll r;

vi min_prime_divisor;
vch primes;
vll f;

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");
	/*
	int n, x;
	cin >> n >> x;

	l.assign(n, 0);
	r.assign(n, 0);
	cost.assign(n, 0);

	FOR(i, 0, n)
		cin >> l[i] >> r[i] >> cost[i];

	FOR(i, 0, n)
		dist.push_back(MP(r[i] - l[i] + 1, i));

	sort(ALL(dist), f);

	bool cha = false;
	ll best = infinity;

	ll h;
	FOR(i, 0, n)
	{
		h = bin(x - dist[i].first, 0, n - 1);
		if (h != -1)
		{
			while(h < n && dist[h].first + dist[i].first == x && !(l[dist[i].second] < r[dist[h].second] || r[dist[i].second] > l[dist[h].second]))
				h++;

			if (h < n && dist[h].first + dist[i].first == x && (l[dist[i].second] < r[dist[h].second] || r[dist[i].second] > l[dist[h].second]))
			{
				best = min(best, cost[dist[i].second] + cost[dist[h].second]);
				cha = true;
			}			
		}
	}

	if (cha == false)
		cout << -1;
	else
		cout << best;
		*/

	cin >> t >> l >> r;

	min_prime_divisor.assign(MAXN, 0);
	f.assign(MAXN, 0);
	FOR(i, 0, MAXN)
		min_prime_divisor[i] = i;
	
	primes.assign(MAXN, 1);
	primes[0] = primes[1] = 0;
	FOR(i, 2, MAXN)
		if (primes[i] == 1)
		{
			for(ll j = i*i; j < MAXN; j += i)
				if (primes[j] == 1)
				{
					primes[j] = 0;
					min_prime_divisor[j] = i;
				}
		}

	f[1] = 0;
	f[2] = 1;
	f[3] = 3;
	f[4] = 3;	
	
	ll ans = 0;
	ll last_t = 1;

	FOR(i, 5, l)
	{
		if (primes[i] == 1)
			f[i] = i*(i - 1) / 2;
		else
			f[i] = f[i/min_prime_divisor[i]] + i * (min_prime_divisor[i] - 1) / 2;
	}

	FOR(i, l, r + 1)
	{
		if (primes[i] == 1)
			f[i] = (i*(i - 1) / 2) % mod;
		else
			f[i] = (f[i / min_prime_divisor[i]] + i * (min_prime_divisor[i] - 1) / 2) % mod;

		ans += last_t * f[i];
		last_t *= t;
		last_t %= mod;
		ans %= mod;
	}
	cout << ans;
	return 0;
}
//don't forget about MAXN, mod and infinity