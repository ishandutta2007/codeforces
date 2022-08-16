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

const int N = 3e5 + 10;

int t[N];
pll c[N];
priority_queue <pll> q;

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i].first;
		c[i].second = i;
	}

	for (int i = 1; i <= k; ++i)
		q.push(c[i]);

	ll ans = 0;
	for (int j = k + 1; j <= k + n; ++j)
	{
		if (j <= n)
			q.push(c[j]);

		pll cur = q.top();
		q.pop();
		ans += cur.first * (j - cur.second);
		t[cur.second] = j;
	}

	cout << ans << endl;
	for (int i = 1; i <= n; ++i)
		cout << t[i] << ' ';
}