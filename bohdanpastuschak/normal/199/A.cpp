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
	cin >> n;

	vector<ll> fibo;
	fibo.push_back(0);
	fibo.push_back(1);
	int i = 2;
	while (true)
	{
		fibo.push_back(fibo[i - 1] + fibo[i - 2]);
		if (fibo[i] > 1000000000) break;
		++i;
	}
	
	FOR(i,0,fibo.size())
		FOR(j,0,fibo.size())
		FOR(k,0,fibo.size())
		if (fibo[i] + fibo[j] + fibo[k] == n)
		{
			cout << fibo[i] << " " << fibo[j] << " "<<fibo[k];
			return 0;
		}



	cout << -1;
	return 0;
}