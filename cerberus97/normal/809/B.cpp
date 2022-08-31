/*
Hanit Banga
*/

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false)

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 5;

int find(int l, int r);
bool exists(int l, int n);
bool query(int i, int j);

int main()
{
	int k, n;
	cin >> n >> k;
	if (k == n)
	{
		cout << "2 1 2" << endl;
		fflush(stdout);
		return 0;
	}

	int first = find(1, n), second;;
	if (first == 1)
		second = find(2, n);

	else if (first == n)
		second = find(1, n - 1);

	else if (exists(first + 1, n))
		second = find(first + 1, n);

	else
		second = find(1, first - 1);

	cout << "2 " << first << ' ' << second << endl;
	fflush(stdout);
}	

int find(int l, int r)
{
	if (l == r)
		return l;

	if (l == r - 1)
	{
		if (query(l, r))
			return l;

		return r;
	}

	int mid = (l + r) / 2;
	if (query(mid, mid + 1))
		return find(l, mid);

	return find(mid + 1, r);
}

bool exists(int l, int n)
{
	if (n - l + 1 <= 3)
	{
		for (int i = l; i <= n; ++i)
		{
			if (query(i, l - 1))
				return true;
		}

		return false;
	}

	int mid = (l + n) / 2;
	if (query(mid, mid + 1))
		return exists(l, mid);

	return true;
}

bool query(int i, int j)
{
	cout << "1 " << i << ' ' << j << endl;
	fflush(stdout);
	string s;
	cin >> s;
	if (s[0] == 'T')
		return true;

	return false;
}