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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e2 + 10, M = 30;

map <int, int> mp;
int a[N], state[5 * N];

int grundy(int i);

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	map <int, int> primes;
	int x = 0;
	for (int i = 1; i <= n; ++i)
	{
		int sq = sqrt(a[i]), temp = a[i];
		for (int j = 2; j <= sq; ++j)
		{
			if (temp % j == 0)
			{
				int ctr = 0;
				while (temp % j == 0)
				{
					temp /= j;
					++ctr;
				}

				if (primes.find(j) == primes.end())
					primes[j] = x++;

				state[primes[j]] |= (1 << ctr);
			}
		}

		if (temp > 1)
		{
			if (primes.find(temp) == primes.end())
				primes[temp] = x++;

			state[primes[temp]] |= (1 << 1);
		}
	}

	int ans = 0;
	for (auto &i : primes)
		ans ^= grundy(state[i.second]);

	if (ans)
		cout << "Mojtaba";
	else
		cout << "Arpa";
}

int grundy(int i)
{
	if (i < 2)
		return 0;

	if (mp.find(i) != mp.end())
		return mp[i];

	set <int> s;
	int largest = 0;
	for (int j = 0; j < M; ++j)
		if (i & (1 << j))
			largest = j;

	for (int j = 1; j <= largest; ++j)
	{
		int temp = i;
		for (int k = j; k < M; ++k)
		{
			if (temp & (1 << k))
			{
				temp -= (1 << k);
				temp |= (1 << (k - j));
			}
		}

		s.insert(grundy(temp));
	}

	int ans = 0;
	while (s.find(ans) != s.end())
		++ans;

	mp[i] = ans;
	return ans;
}