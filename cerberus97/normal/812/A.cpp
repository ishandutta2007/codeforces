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

const int N = 10;

int l[N], s[N], p[N], r[N];

int main()
{
	for (int i = 0; i < 4; ++i)
		cin >> l[i] >> s[i] >> r[i] >> p[i];

	bool ans = false;
	for (int i = 0; i < 4; ++i)
	{
		if (p[i] and (l[i] or s[i] or r[i] or l[(i + 1) % 4] or r[(i + 3) % 4] or s[(i + 2) % 4]))
			ans = true;
	}

	if (ans)
		cout << "YES";

	else
		cout << "NO";
}