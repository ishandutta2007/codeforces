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

const int N = 1e6 + 5;

bool hole[N] = {0};

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	while (m--)
	{
		int a;
		cin >> a;
		hole[a] = true;
	}

	int x = 1;
	while (k--)
	{
		if (hole[x] == true)
			break;

		int u, v;
		cin >> u >> v;
		if (u == x)
			x = v;
		else if (v == x)
			x = u;
	}

	cout << x;
}