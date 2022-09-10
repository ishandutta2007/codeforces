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

int main()
{
	srand(time(NULL));
	clock_t startTime = clock();
	ios_base::sync_with_stdio(false), cin.tie(0);
	//ifstream in("In.txt");

	vch is;
	is.assign(1000000, 1);
	is[0] = 0;
	is[1] = 0;
	FOR(i, 2, 1000000)
		if (is[i] == 1)
			for (ll j = i*i; j <= 1000000; j += i)
				is[j] = 0;

	set<ll> t_prime;
	FOR(i, 2, 1000000)
		if (is[i] == 1)
			t_prime.insert(i*i);

	ll n; cin >> n;
	REPEAT(n)
	{
		ll x; cin >> x;
		if (t_prime.find(x) != t_prime.end())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
//don't forget about MAXN, mod and infinity