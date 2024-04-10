#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, int> pii;

const int MAX_INT = (1 << 31)-1;
const ll MAX_LL = (1LL << 63)-1;
const ll BIG_LL = 1e18;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll p,q;
	int n;
	ll a[90];
	cin >> p >> q >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n-1; ++i)
	{
		if (a[i] > BIG_LL / q)
		{
			cout << "NO" << endl;
			return 0;
		}
		p -= a[i]*q;
		if (p <= 0)
		{
			cout << "NO" << endl;
			return 0;
		}
		swap(p, q);
	}
	if (a[n-1] <= BIG_LL / q && p == a[n-1]*q)
		cout << "YES";
	else
		cout << "NO";
	cout << endl;
	return 0;
}