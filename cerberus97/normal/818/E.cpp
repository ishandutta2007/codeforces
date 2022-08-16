/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5, K = 50;

int a[N], prime[K], m = 0;
vector <int> af[N];

vector <int> get_num(int num);
vector <int> convert(int num);
vector <int> multiply(vector <int> v1, vector <int> v2);
vector <int> divide(vector <int> v1, vector <int> v2);
bool is_divisible(vector <int> v1, vector <int> v2);

int main()
{
	int n, k;
	cin >> n >> k;
	vector <int> kf = get_num(k);
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		af[i] = convert(a[i]);
	}

	int l = 1, r = 1;
	vector <int> prod = af[1];
	ll ans = 0;
	while (true)
	{
		// cout << l << ' ' << r << ' ' << prod[0] << ' ' << prod[1] << endl;
		if (l <= r and is_divisible(prod, kf))
		{
			prod = divide(prod, af[l]);
			++l;
			continue;
		}

		ans += l - 1;
		if (r == n)
			break;

		++r;
		prod = multiply(prod, af[r]);
	}

	cout << ans;
}

vector <int> get_num(int num)
{
	int sq = sqrt(num);
	vector <int> ans;
	for (int i = 2; i <= sq; ++i)
	{
		if (num % i == 0)
		{
			prime[m++] = i;
			int ctr = 0;
			while (num % i == 0)
			{
				num /= i;
				++ctr;
			}

			ans.pb(ctr);
		}
	}

	if (num > 1)
	{
		prime[m++] = num;
		ans.pb(1);
	}

	return ans;
}

vector <int> convert(int num)
{
	vector <int> ans;
	for (int i = 0; i < m; ++i)
	{
		int ctr = 0;
		while (num % prime[i] == 0)
		{
			num /= prime[i];
			++ctr;
		}

		ans.pb(ctr);
	}

	return ans;
}

vector <int> multiply(vector <int> v1, vector <int> v2)
{
	vector <int> ans;
	for (int i = 0; i < m; ++i)
		ans.pb(v1[i] + v2[i]);

	return ans;
}

vector <int> divide(vector <int> v1, vector <int> v2)
{
	vector <int> ans;
	for (int i = 0; i < m; ++i)
		ans.pb(v1[i] - v2[i]);

	return ans;
}

bool is_divisible(vector <int> v1, vector <int> v2)
{
	for (int i = 0; i < m; ++i)
		if (v1[i] < v2[i])
			return false;

	return true;
}