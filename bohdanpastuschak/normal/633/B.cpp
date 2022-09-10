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

int main()
{
	ll m;
	cin >> m;

	ll ans = 0;
	int i = 5;
	int t;
	while (true)
	{
		 t = i;
		 while (t % 5 == 0)
		 {
			 t /= 5;
			 ans++;
		 }
		 if (ans == m) break;
		 if (ans > m)
		 {
			 cout << 0;
			 return 0;
		 }
		 i += 5;
	}

	cout << 5<<endl<<i<<" "<<i+1<<" "<<i+2<<" "<<i+3<<" "<<i+4;
	return 0;
}