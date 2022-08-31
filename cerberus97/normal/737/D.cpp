#include <iostream>
#include <cstdlib>
#include <cstdio>
// #include <cassert>
// #include <map>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 4005, K = 90;

bool sIg[N][K][K], sZh[N][2*K][K];
int ig[N][K][K], zh[N][2*K][K];
int n, a[N], prefix[N];

int solveZh(int l, int r, int k);

inline int sum(int l, int r)
{
	if (l > r)
		return 0;

	return prefix[r] - prefix[l-1];
}

int solveIg(int l, int r, int k)
{
	// assert(n-r-l+1 <= k-1);
	// assert(n-r-l+1 >= 0);

	if (l + k > r + 1)
		return (sum(1,l-1) - sum(r+1,n));

	int id = l*N + r, d = n-r-l+1;

	if (sIg[l][d][k])
		return ig[l][d][k];

	sIg[l][d][k] = true;

	int ans = solveZh(l+k, r, k);

	if (l + k <= r)
		ans = max(ans, solveZh(l+k+1, r, k+1));

	ig[l][d][k] = ans;
	return ans;
}

int solveZh(int l, int r, int k)
{
	// assert(n-r-l+1 <= k-1);
	// assert(n-r-l+1 >= -k);

	if (l + k > r + 1)
		return (sum(1,l-1) - sum(r+1,n));

	int id = l*N + r, d = n-r-l+1+K;

	if (sZh[l][d][k])
		return zh[l][d][k];

	sZh[l][d][k] = true;

	int ans = solveIg(l, r-k, k);

	if (l + k <= r)
		ans = min(ans, solveIg(l, r-k-1, k+1));

	zh[l][d][k] = ans;
	return ans;
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	prefix[0] = 0;

	for (int i = 1; i <= n; ++i)
		prefix[i] = prefix[i-1] + a[i];

	cout << solveIg(1, n, 1);

	fflush(stdout);
	_Exit(0);
}