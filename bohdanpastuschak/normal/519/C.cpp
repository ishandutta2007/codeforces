#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cassert>
#include <deque>
#include <memory.h>
#include <cstdio>
#include <cctype>
#include <sstream>
#include <stack>
#include <utility>
#include <complex>
using namespace std;
#define ll unsigned long long
#define mod 1000000007
#define male -mod
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define RFOR(i, b, a) for (ll i = (b-1); i>=(a); --i)
#define vec(a,n) vector<ll> a(n)

int main()
{
	ll n, m;
	cin >> n >> m;

	ll ans = 0;
	while (n *m >= 2)
	{
		if (n == 1) {
			ans++; break;
		}
		if (m == 1) {
			ans++; break;
		}
		while (n >= 2 * m && m > 0)
		{
			n -= 2;
			m -= 1;
			ans++;
		}
		while (m >= 2 * n && n > 0)
		{
			n -= 1;
			m -= 2;
			ans++;
		}
		if (n >= 3 && m >= 3)
		{
			n -= 3;
			m -= 3;
			ans += 2;
		}
		if (n == 2 && m == 3)
		{
			ans++;
			break;
		}
		if (n == 3 && m == 2)
		{
			ans++;
			break;
		}
		if (m == 2 && n == 2)
		{
			ans++;
			break;
		}
	}
	cout << ans;
	return 0;
}