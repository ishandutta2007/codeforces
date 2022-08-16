/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 100;

bool b[N] = {0};
int a[N] = {0};

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n - k + 1; ++i)
	{
		string s;
		cin >> s;
		if (s[0] == 'Y')
			b[i] = true;
	}

	for (int i = n - k + 2, j = 0; i <= n; ++i, ++j)
		a[i] = j;

	for (int i = n - k + 1; i >= 1; --i)
	{
		if (!b[i])
		{
			a[i] = a[i + k - 1];
			continue;
		}

		set <int> available;
		for (int j = 0; j < n; ++j)
			available.insert(j);

		for (int j = i + 1; j < i + k; ++j)
			available.erase(a[j]);

		a[i] = *available.begin();
	}

	for (int i = 1; i <= n; ++i)
	{
		int x = a[i] / 26, y = a[i] % 26;
		cout << (char)(x + 'A') << (char)(y + 'a') << ' ';
	}
}