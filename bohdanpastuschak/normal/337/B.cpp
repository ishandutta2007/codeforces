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
	int a, b, c, d;
	cin >> a >> b >> c >> d;


	ll p, q;
	if (a >= c&& b >= d)
	{
		if ((b / (d + 0.000001)) > (a / (c + 0.000001)))
		{
			p = a*d;
			q = b*c;
		}
		else
		{
			p = b*c;
			q = a*d;
		}
	}
	else
	{
		if (a >= c)
		{
			p = c*b;
			q = a*d;
		}
		else
		{
			if (b >= d)
			{
				p = a*d;
				q = b*c;
			}
			else
			{
				if ((d / (b + 0.000001)) > (c / (a + 0.000001)))
				{
					p = c*b;
					q = a*d;
				}
				else
				{
					p = a*d;
					q = c*b;
				}
			}
		}
	}

	p = q - p;
	if (p == 0)
	{
		cout << "0/1";
		return 0;
	}

	ll gg = gcd(p, q);
	p /= gg;
	q /= gg;

	cout << p << "/" << q;
	return 0;
}