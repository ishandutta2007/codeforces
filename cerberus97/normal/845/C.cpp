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

const int N = 2e5 + 10;

vector <pii> events;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int l, r;
		cin >> l >> r;
		events.pb({l, r});
	}

	sort(events.begin(), events.end());
	int tv1 = 0, tv2 = 0;
	for (auto &i : events)
	{
		int l = i.first, r = i.second;
		if (l < tv1 and l < tv2)
		{
			cout << "NO";
			return 0;
		}

		if (l >= tv1)
			tv1 = r + 1;

		else
			tv2 = r + 1;
	}

	cout << "YES";
}