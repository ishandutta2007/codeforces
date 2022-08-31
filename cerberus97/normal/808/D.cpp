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

ll a[N];

int main()
{
	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	if (sum % 2)
	{
		cout << "NO";
		return 0;
	}

	sum /= 2;
	multiset <ll> l, r;
	for (int i = 0; i < n; ++i)
		r.insert(a[i]);

	for (int i = 0; i < n; ++i)
	{
		l.insert(a[i]);
		r.erase(r.find(a[i]));
		sum -= a[i];
		if (sum == 0 or l.find(-sum) != l.end() or r.find(sum) != r.end())
		{
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
}