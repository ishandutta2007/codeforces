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

const int N = 500;

int a[N], b[N];

int main()
{
	int n, k;
	cin >> n >> k;	
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int i = 0; i < k; ++i)
		cin >> b[i];

	sort(b, b + k, greater <int>());
	for (int i = 0, j = 0; i < n; ++i)
	{
		if (a[i] == 0)
			a[i] = b[j++];
	}

	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] > a[i + 1])
		{
			cout << "Yes";
			return 0;
		}
	}

	cout << "No";
}