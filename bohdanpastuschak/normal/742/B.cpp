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
#define MAXN 100001

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

int ord(ll a, ll p)
{
	int ans = 0;
	while (a%p == 0)
	{
		a /= p;
		ans++;
	}
	return ans;
}

bool isPrime(ll a)
{
	for (ll i = 2; i*i <= a; ++i)
		if (a%i == 0)
			return 0;
	return 1;
}

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	int n;
	cin >> n;
	int x;
	cin >> x;

	vi a(n);
	FOR(i, 0, n)
		cin >> a[i];

	map<int, ll> m;
	FOR(i, 0, n)
		m[a[i]]++;

	if (x > 0)
	{

		ll ans = 0;

		FOR(i, 0, n)
			ans += m[a[i] ^ x];

		cout << ans / 2;
	}
	else
	{
		ll ans = 0;

		for (auto i : m)
			ans += i.second*(i.second - 1) / 2;

		cout << ans;
	}
	return 0;
}
//don't forget about MAXN, mod and infinity