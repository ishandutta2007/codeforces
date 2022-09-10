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
	string n;
	cin >> n;
	if (n.length() < 2)
	{
		int t = n[0] - 48;
		if (t % 4 == 0)cout << 4;
		else cout << 0;
		return 0;
	}
	int last = n[n.length() - 1] - 48;
	int prelast = n[n.length() - 2] - 48;

	if ((prelast * 10 + last) % 4 == 0)cout << 4;
	else
		cout << 0;
	return 0;
}