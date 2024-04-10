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
#define ll long long
#define mod 1073741824
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define vec(a,n) vector<ll>a(n)
#define newVecRead(a,n) vec(a,n); FOR(i,0,n)cin>>a[i]
#define sortVec(a) sort(a.begin(), a.end())

bool isPrime(ll n)
{
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 2; i*i <= n; ++i)
		if (n%i == 0)return false;
	return true;
}

ll tau(ll n)
{
	if (n == 1) return 1;
	if (isPrime(n)) return 2;
	ll ans = 1;
	FOR(i, 2, n + 1)
	{
		int exp = 0;
		while (n%i == 0)
		{
			n /= i;
			++exp;
		}
		ans *= (exp + 1);
	}

	return ans;
}

ll gcd(ll a, ll b)
{
	if (a%b == 0) return b;
	if (b%a == 0) return a;
	if (a == b) return a;
	if (a == 1 || b == 1) return 1;
	return gcd(max(a, b) % (min(a, b)), min(a, b));
}

int main()
{
	ll n;
	ll m;
	cin >> n >> m;
	ll ans = 0;

	vec(d1, 5);
	FOR(i, 0, 5)
		d1[i] = n / 5;
	if (n % 5 > 0 )d1[1]++;
	if (n % 5 > 1)d1[2]++;
	if (n % 5 > 2)d1[3]++;
	if (n % 5 > 3)d1[4]++;

	vec(d2, 5);
	FOR(i, 0, 5)
		d2[i] = m / 5;
	if (m % 5 > 0)d2[1]++;
	if (m % 5 > 1)d2[2]++;
	if (m % 5 > 2)d2[3]++;
	if (m % 5 > 3)d2[4]++;

	ans += d1[0] * d2[0];
	ans += d1[1] * d2[4];
	ans += d1[2] * d2[3];
	ans += d1[3] * d2[2];
	ans += d1[4] * d2[1];
	
	cout << ans;
	return 0;
}