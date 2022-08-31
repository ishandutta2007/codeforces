/*
Hanit Banga
*/

#include <iostream>
#include <vector>
#include "cstring"

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 5;

int c[N];
bool del[N];

bool isPresent(string a, string b, int n, int m);

int main()
{
	string a, b;
	cin >> a >> b;

	int n = a.length(), m = b.length();
	for (int i = 0; i < n; ++i)
		cin >> c[i];

	int l = 1, r = n - 1;
	while (l <= r)
	{
		memset(del, 0, sizeof(del));
		int mid = (l + r) / 2;
		for (int i = 0; i < mid; ++i)
			del[c[i] - 1] = true;

		if (isPresent(a, b, n, m))
			l = mid + 1;
		else
			r = mid - 1;
	}

	cout << l - 1;
}

bool isPresent(string a, string b, int n, int m)
{
	int i = 0, j = 0;
	while (i < n and j < m)
	{
		if (del[i])
		{
			++i;
			continue;
		}

		if (a[i] == b[j])
			++j;

		++i;
	}

	return (j == m);
}