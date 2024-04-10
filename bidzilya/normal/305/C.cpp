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

const int N = 1e5;
int a[N], c[N];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	int ans = 1;
	c[0] = 1;
	for (int i=1; i<n; ++i)
		if (a[i] == a[ans-1])
			++c[ans-1];
		else
		{
			c[ans] = 1;
			a[ans] = a[i];
			++ans;
		}
	n = ans;
	ans = 0;
	int last = 0;
	for (int i=0; i<n; )
	{
		ans += a[i]-last;
		last = a[i]+1;
		ans += (c[i]%2 == 0);
		c[i] /= 2;
		if (!c[i])
			++i;
		else
		{
			++a[i];
			if (i+1 < n && a[i+1] == a[i])
			{
				c[i+1] += c[i];
				++i;
			}
		}
	}
	cout << ans << endl;
	return 0;
}